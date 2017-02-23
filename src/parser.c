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
parse_file (struct doc_config *conf, struct doc_object *objs, const char *filename)
{
	FILE *f_src = fopen (filename, "r");
	if (f_src == NULL)
	{
		return NULL;
	}
	
	char line[250];
	const char *cursor;
	bool mode = false;
	
	enum element_type type;
	union doc_element fields;
	
	// Some constants
	const size_t len_block = strlen (conf->pattern[DOC_PATTERN_BLOCK]);
	const size_t len_return = strlen (conf->pattern[DOC_PATTERN_RETURN]);
	
	while (fgets (line, sizeof (line), f_src) != NULL)
	{	
		// Enter the documentation mode
		if (!mode && strstr (line, conf->pattern[DOC_PATTERN_ENTER]) != NULL)
		{
			type = DOC_ELEMENT_FUNCTION;
			mode = true;
		}
		// Exit the documentation mode
		else if (mode && strstr (line, conf->pattern[DOC_PATTERN_EXIT]) != NULL)
		{
			objs = object_append (objs, type, &fields);
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
			
			// Argument
			if (cursor[0] == '@')
			{
				function_arg_insert (&fields.func, strspn_c (cursor + 1, " -"),
						     strdup (strstr (cursor, "- ") + 2));
			}
			// Function name
			else if (strstr (cursor, conf->pattern[DOC_PATTERN_FUNCTION]) != NULL)
			{
				function_init (&fields.func, strspn_c (cursor, conf->pattern[DOC_PATTERN_FUNCTION]));
			}
			// Return
			else if (strncmp (cursor, conf->pattern[DOC_PATTERN_RETURN],
					  len_block) == 0)
			{	
				fields.func.returns = strdup (cursor + len_return);
			}
			// Function description
			else
			{
				fields.func.description = realloc (fields.func.description, (strlen (fields.func.description) + strlen (cursor) + 1) * sizeof (char));
				strcat (fields.func.description, cursor);
			}
		}
	}
	
	fclose (f_src);
	return objs;
}
