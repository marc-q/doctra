/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include <string.h>
#include "../object.h"
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
export_md_function (struct doc_function *self, FILE *f_doc)
{
	// Function name
	fputs (self->name, f_doc);
	fputs ("\n", f_doc);
	
	// Underline
	for (size_t i = 0; i < strlen (self->name); i++)
	{
		fputs ("=", f_doc);
	}
	fputs ("\n", f_doc);
	
	// Function description
	fputs (self->description, f_doc);
	fputs ("\n", f_doc);
	
	// Parameters
	fputs ("\n**Parameters**\n\n", f_doc);
	fputs ("**Name** | **Description**\n", f_doc);
	fputs ("-------- | ---------------\n", f_doc);
	
	for (size_t i = 0; i < self->args_amnt; i++)
	{
		fputs (self->args[DOC_ARGS_NAME][i], f_doc);
		fputs (" | ", f_doc);
		fputs (self->args[DOC_ARGS_DESC][i], f_doc);
	}
	
	// Returns
	fputs ("\n**Returns**\n", f_doc);
	fputs (self->returns, f_doc);
	fputs ("\n", f_doc);
}

/**
 * export_md()
 * @objs - The list head.
 * @filename - The name of the documentation file.
 *
 * Exports the objects in Markdown to a file named @filename.
 *
 * Return: none
 */
void
export_md (struct doc_object *objs, const char *filename)
{
	FILE *f_doc = fopen (filename, "w");
	if (f_doc == NULL)
	{
		return;
	}
	
	struct doc_object *next = objs;
	while (next)
	{
		switch (next->type)
		{
			case DOC_ELEMENT_FUNCTION:
				export_md_function (&next->element.func, f_doc);
				break;
			default:
				break;
		}
		next = next->next;
	}
	fclose (f_doc);
}
