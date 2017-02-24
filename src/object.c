/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include "strlist.h"
#include "objects.h"

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
		
		switch (list->type)
		{
			case DOC_ELEMENT_FUNCTION:
				function_free (&list->element.func);
				break;
			default:
				break;
		}
		
		free (list);
		list = next;
	}
}
