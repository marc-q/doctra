/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include <string.h>
#include "object.h"

// DOC_FUNCTION

/**
 * function_init()
 * @self - The structure itself.
 * @name - The name of the function.
 *
 * Initialize's a doc_function structure.
 *
 * Return: none
 */
void
function_init (struct doc_function *self, char *name)
{
	self->name = name;
	self->description = strdup ("");
	self->returns = NULL;
	
	// Parameter
	self->args_amnt = 0;
	self->args[DOC_ARGS_NAME] = NULL;
	self->args[DOC_ARGS_DESC] = NULL;
}

/**
 * function_free()
 * @self - The structure itself.
 *
 * Free's the allocated memory of a function structure.
 *
 * Return: none
 */
void
function_free (struct doc_function *self)
{
	free (self->name);
	free (self->description);
	free (self->returns);
	
	for (size_t i = 0; i < self->args_amnt; i++)
	{
		free (self->args[DOC_ARGS_NAME][i]);
		free (self->args[DOC_ARGS_DESC][i]);
	}
	
	if (self->args_amnt > 0)
	{
		free (self->args[DOC_ARGS_NAME]);
		free (self->args[DOC_ARGS_DESC]);
	}
}

/**
 * function_arg_insert()
 * @self - The function object itself.
 * @name - Name of the argument.
 * @description - Description of the argument.
 *
 * Insert a new argument/parameter to the function.
 *
 * Return: none
 */
void
function_arg_insert (struct doc_function *self, char *name, char *description)
{
	const size_t size = sizeof (char**) * (++self->args_amnt);
	self->args[DOC_ARGS_NAME] = realloc (self->args[DOC_ARGS_NAME], size);
	self->args[DOC_ARGS_DESC] = realloc (self->args[DOC_ARGS_DESC], size);
	
	self->args[DOC_ARGS_NAME][self->args_amnt - 1] = name;
	self->args[DOC_ARGS_DESC][self->args_amnt - 1] = description;
}

// DOC_OBJECT

/**
 * object_append()
 * @list - List head.
 * @type - The type of the element.
 * @element - The element.
 *
 * Append's an entry to the linked list.
 *
 * Return: Pointer to the list head.
 */
struct doc_object*
object_append (struct doc_object *list, const enum element_type type, const union doc_element *element)
{
	struct doc_object *new = malloc (sizeof (struct doc_object));
	
	new->type = type;
	new->element = *element;
	new->next = NULL;
	
	if (list)
	{
		struct doc_object *last = list;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new;
		return list;
	}
	return new;
}

/**
 * object_free()
 * @list - List head.
 *
 * Free's the whole linked list.
 *
 * Return: none
 */
void
object_free (struct doc_object *list)
{
	struct doc_object *next;
	
	while (list)
	{
		next = list->next;
		
		function_free (&list->element.func);
		
		free (list);
		list = next;
	}
}
