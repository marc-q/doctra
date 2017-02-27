/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include <string.h>
#include "../object.h"
#include "../node.h"
#include "export_md.h"

/**
 * export_md_function()
 * @self - The function data.
 * @f_doc - Stream to which the data gets written.
 *
 * Exports a function object to the file @f_doc
 * in Markdown.
 *
 * Return: none
 */
static void
export_md_function (struct doc_object *self, FILE *f_doc)
{	
	// Description
	if (self->description != NULL)
	{ 
		fputs (self->description, f_doc);
	}
	
	// Parameters
	fputs ("\n**Parameters**\n\n", f_doc);
	fputs ("**Name** | **Description**\n", f_doc);
	fputs ("-------- | ---------------\n", f_doc);
	
	for (size_t i = 0; i < self->members_amnt; i++)
	{
		fputs (self->members[OBJ_MEMBERS_NAME][i], f_doc);
		fputs (" | ", f_doc);
		fputs (self->members[OBJ_MEMBERS_DESC][i], f_doc);
		fputc ('\n', f_doc);
	}
	
	// Returns
	if (self->returns != NULL)
	{
		fputs ("\n**Returns**\n", f_doc);
		fputs (self->returns, f_doc);
		fputs ("\n\n", f_doc);
	}
}

/**
 * export_md_struct()
 * @self - The struct data.
 * @f_doc - Stream to which the data gets written.
 *
 * Exports a struct object to the file @f_doc
 * in Markdown.
 *
 * Return: none
 */
static void
export_md_struct (struct doc_object *self, FILE *f_doc)
{	
	// Description
	if (self->description != NULL)
	{
		fputs (self->description, f_doc);
	}
	
	// Members
	fputs ("\n**Members**\n\n", f_doc);
	fputs ("**Name** | **Description**\n", f_doc);
	fputs ("-------- | ---------------\n", f_doc);
	
	for (size_t i = 0; i < self->members_amnt; i++)
	{
		fputs (self->members[OBJ_MEMBERS_NAME][i], f_doc);
		fputs (" | ", f_doc);
		fputs (self->members[OBJ_MEMBERS_DESC][i], f_doc);
		fputc ('\n', f_doc);
	}
}

/**
 * export_md()
 * @nodes - The list head.
 * @filename - The name of the documentation file.
 *
 * Exports the @nodes in Markdown to a file named @filename.
 *
 * Return: none
 */
void
export_md (struct doc_node *nodes, const char *filename)
{
	FILE *f_doc = fopen (filename, "w");
	if (f_doc == NULL)
	{
		return;
	}
	
	struct doc_node *next = nodes;
	while (next)
	{
		// The name of the object as H1
		fputc ('#', f_doc);
		fputs (next->name, f_doc);
		fputc ('\n', f_doc);
		
		switch (next->type)
		{
			case DOC_NODE_FUNCTION:
				export_md_function (&next->element, f_doc);
				break;
			case DOC_NODE_STRUCT:
				export_md_struct (&next->element, f_doc);
				break;
			default:
				break;
		}
		next = next->next;
	}
	fclose (f_doc);
}
