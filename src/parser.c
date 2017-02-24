/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"
#include "objects.h"
#include "parser.h"

/**
 * strspn_c()
 * @str - String.
 * @end - Ending sequence.
 *
 * A simple shortcut.
 *
 * Return: a new allocated substring of @str that ends at @end.
 */
static char*
strspn_c (const char *str, const char *end)
{
	return strndup (str, (size_t) (strstr (str, end) - str));
}

/**
 * parse_function()
 * @conf - The configuration.
 * @func - Function object.
 * @cursor - String to parse.
 *
 * Parses fields of a function object.
 *
 * Return: none
 */
static void
parse_function (const struct doc_config *conf, struct doc_function *func, const char *cursor)
{
	// Argument
	if (cursor[0] == DOC_PATTERN_MEMBER)
	{
		function_arg_insert (func, strspn_c (cursor + 1, DOC_PATTERN_MDELIM),
					strdup (strstr (cursor, DOC_PATTERN_MDELIM) + conf->len_mdelim));
	}
	// Return
	else if (strncmp (cursor, DOC_PATTERN_RETURN, conf->len_return) == 0)
	{	
		func->returns = strdup (cursor + conf->len_return);
	}
	// Description
	else
	{
		func->description = realloc (func->description,
			(strlen (func->description) + strlen (cursor) + 1) * sizeof (char));
		strcat (func->description, cursor);
	}
}

/**
 * parse_struct()
 * @conf - The configuration.
 * @struc - Struct object.
 * @cursor - String to parse.
 *
 * Parses fields of a struct object.
 *
 * Return: none
 */
static void
parse_struct (const struct doc_config *conf, struct doc_struct *struc, const char *cursor)
{
	// Member
	if (cursor[0] == DOC_PATTERN_MEMBER)
	{
		struct_member_insert (struc, strspn_c (cursor + 1, DOC_PATTERN_MDELIM),
					strdup (strstr (cursor, DOC_PATTERN_MDELIM) + conf->len_mdelim));
	}
	// Description
	else
	{
		struc->description = realloc (struc->description,
			(strlen (struc->description) + strlen (cursor) + 1) * sizeof (char));
		strcat (struc->description, cursor);
	}
}

/**
 * parse_object()
 * @conf - The configuration.
 * @fields - Element object.
 * @type - The object type will be stored here.
 * @cursor - String to parse.
 *
 * Parses a object type and initialize it.
 *
 * Return: none
 */
static void
parse_object (const struct doc_config *conf, union doc_element *fields, enum element_type *type, const char *cursor)
{
	// Function name
	if (strstr (cursor, DOC_PATTERN_FUNCTION) != NULL)
	{
		*type = DOC_ELEMENT_FUNCTION;
		function_init (&fields->func,
				strspn_c (cursor, DOC_PATTERN_FUNCTION));
	}
	// Struct name
	else if (strncmp (cursor, DOC_PATTERN_STRUCT, conf->len_struct) == 0)
	{
		*type = DOC_ELEMENT_STRUCT;
		struct_init (&fields->struc, strdup (&cursor[conf->len_struct]));
	}
}

/**
 * parse_file()
 * @conf - The configuration.
 * @objs - The list head.
 * @filename - Name of the source file.
 *
 * Parses a source file and returns a doc_object linked list
 * which contains the information gathered from the source file.
 *
 * Return: A linked list containing the information.
 */
struct doc_object*
parse_file (const struct doc_config *conf, struct doc_object *objs, const char *filename)
{
	FILE *f_src = fopen (filename, "r");
	if (f_src == NULL)
	{
		return NULL;
	}
	
	char line[250];
	const char *cursor;
	bool mode = false;
	
	enum element_type type = DOC_ELEMENT_NONE;
	union doc_element fields;
	
	// Some constants
	const size_t len_block = strlen (conf->pattern[DOC_PATTERN_BLOCK]);
	
	while (fgets (line, sizeof (line), f_src) != NULL)
	{	
		// Enter the documentation mode
		if (!mode && strstr (line, conf->pattern[DOC_PATTERN_ENTER]) != NULL)
		{
			type = DOC_ELEMENT_NONE;
			mode = true;
		}
		// Exit the documentation mode
		else if (mode && strstr (line, conf->pattern[DOC_PATTERN_EXIT]) != NULL)
		{
			if (type != DOC_ELEMENT_NONE)
			{
				objs = object_append (objs, type, &fields);
			}
			mode = false;
		}
		else if (mode)
		{
			cursor = strstr (line, conf->pattern[DOC_PATTERN_BLOCK]);
			
			// Empty line
			if (cursor == NULL)
			{
				continue;
			}
			
			// Skip the first two characters
			cursor += len_block;
			
			// Parse the object
			switch (type)
			{
				case DOC_ELEMENT_NONE:
					parse_object (conf, &fields, &type, cursor);
					break;
				case DOC_ELEMENT_FUNCTION:
					parse_function (conf, &fields.func, cursor);
					break;
				case DOC_ELEMENT_STRUCT:
					parse_struct (conf, &fields.struc, cursor);
					break;
				default:
					break;
			}
		}
	}
	
	fclose (f_src);
	return objs;
}
