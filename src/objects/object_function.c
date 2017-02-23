/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include <string.h>
#include "../strlist.h"
#include "object_function.h"

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
	self->args[FUNCTION_ARGS_NAME] = NULL;
	self->args[FUNCTION_ARGS_DESC] = NULL;
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
	
	strlist_free (self->args, FUNCTION_ARGS_LAST, self->args_amnt);
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
	self->args[FUNCTION_ARGS_NAME] = strlist_insert (self->args[FUNCTION_ARGS_NAME],
							name, ++self->args_amnt);
						    
	self->args[FUNCTION_ARGS_DESC] = strlist_insert (self->args[FUNCTION_ARGS_DESC],
							description, self->args_amnt); 
}
