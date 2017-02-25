/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include "object.h"
#include "node.h"

/**
 * node_init()
 * @self - Node to initialize.
 * @type - Type of the node.
 * @name - Name of the node.
 *
 * Initializes a node structure and its element.
 *
 * Return: none
 */
void
node_init (struct doc_node *self, const enum node_type type, char *name)
{
	self->type = type;
	self->name = name;
	self->next = NULL;
	
	object_init (&self->element);
}

/**
 * node_append()
 * @list - List head.
 * @type - Type of the node.
 * @element - The element.
 *
 * Appends an entry to the linked list.
 *
 * Return: Pointer to the list head.
 */
struct doc_node*
node_append (struct doc_node *list, const struct doc_node *node)
{
	struct doc_node *new = malloc (sizeof (struct doc_node));
	
	// Copy the node
	*new = *node;
	
	if (list)
	{
		struct doc_node *last = list;
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
 * node_free()
 * @list - List head.
 *
 * Frees the whole linked list.
 *
 * Return: none
 */
void
node_free (struct doc_node *list)
{
	struct doc_node *next;
	
	while (list)
	{
		next = list->next;
		
		if (list->type != DOC_NODE_NONE)
		{
			object_free (&list->element);
		}
		free (list->name);
		free (list);
		list = next;
	}
}
