/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_utils.h"
#include "config.h"
#include "object.h"
#include "node.h"
#include "parser.h"

/**
 * parse_object()
 * @self - The object to insert the data.
 * @cursor - String to parse.
 *
 * Parses fields of a doc_object.
 *
 * Return: none
 */
static void
parse_object (struct doc_object *self, const char *cursor)
{
	// Member
	if (string_match_start (cursor, DOC_PATTERN_MEMBER))
	{
		object_member_insert (self, strspan_c (&cursor[1], DOC_PATTERN_MDELIM),
					strspan (cursor, DOC_PATTERN_MDELIM, "\n"));
	}
	// Return
	else if (string_match_start (cursor, DOC_PATTERN_RETURN))
	{	
		self->returns = strspan_c (&cursor[strlen (DOC_PATTERN_RETURN)], "\n");
	}
	// Description
	else
	{
		self->description = string_recat (self->description, cursor);
	}
}

/**
 * parse_node()
 * @node - Node to store the object in.
 * @cursor - String to parse.
 *
 * Parses a node type and initialize it.
 *
 * Return: none
 */
static void
parse_node (struct doc_node *node, const char *cursor)
{
	// Function name
	if (string_match_end (cursor, DOC_PATTERN_FUNCTION))
	{
		node_init (node, DOC_NODE_FUNCTION, strspan_c (cursor, DOC_PATTERN_FUNCTION));
	}
	// Struct name
	else if (string_match_start (cursor, DOC_PATTERN_STRUCT))
	{
		node_init (node, DOC_NODE_STRUCT,
				strspan_c (&cursor[strlen (DOC_PATTERN_STRUCT)], "\n"));
	}
}

/**
 * parse_file()
 * @conf - The configuration.
 * @nodes - The list head.
 * @filename - Name of the source file.
 *
 * Parses a source file and returns a doc_node linked list
 * which contains the information gathered from the source file.
 *
 * Return: A linked list containing the information.
 */
struct doc_node*
parse_file (const struct doc_config *conf, struct doc_node *nodes, const char *filename)
{
	FILE *f_src = fopen (filename, "r");
	if (f_src == NULL)
	{
		return NULL;
	}
	
	char line[250];
	const char *cursor;
	bool mode = false;
	
	struct doc_node node;
	
	// Some constants
	const size_t len_block = strlen (conf->pattern[DOC_PATTERN_BLOCK]);
	
	while (fgets (line, sizeof (line), f_src) != NULL)
	{	
		// Enter the documentation mode
		if (!mode && strstr (line, conf->pattern[DOC_PATTERN_ENTER]) != NULL)
		{
			node.type = DOC_NODE_NONE;
			mode = true;
		}
		// Exit the documentation mode
		else if (mode && strstr (line, conf->pattern[DOC_PATTERN_EXIT]) != NULL)
		{
			if (node.type != DOC_NODE_NONE)
			{
				nodes = node_append (nodes, &node);
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
			
			// Try parsing the node
			if (node.type == DOC_NODE_NONE)
			{
				parse_node (&node, cursor);
			}
			// Parse the object
			else
			{
				parse_object (&node.element, cursor);
			}
		}
	}
	
	fclose (f_src);
	return nodes;
}
