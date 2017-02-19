/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include <string.h>
#include "config.h"

/**
 * config_init()
 * @self - Pointer to the structure to init.
 *
 * Initialize a config structure.
 *
 * Return: none
 */
void
config_init (struct doc_config *self)
{
	// Set the default values
	self->pattern[DOC_PATTERN_ENTER] = strdup ("/**");
	self->pattern[DOC_PATTERN_EXIT] = strdup ("*/");
	self->pattern[DOC_PATTERN_BLOCK] = strdup ("* ");
	self->pattern[DOC_PATTERN_RETURN] = strdup ("Return: ");
	self->pattern[DOC_PATTERN_FUNCTION] = strdup ("()");
}

/**
 * config_free()
 * @self - Pointer to the structure to free.
 *
 * Free's the allocated memory of a config
 * structure.
 *
 * Return: none
 */
void
config_free (struct doc_config *self)
{
	for (size_t i = 0; i < DOC_PATTERN_LAST; i++)
	{
		free (self->pattern[i]);
	}
}
