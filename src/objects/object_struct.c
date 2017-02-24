/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include <string.h>
#include "../strlist.h"
#include "object_struct.h"

/**
 * struct_init()
 * @self - The structure itself.
 * @name - The name of the struct.
 *
 * Initialize's a doc_struct structure.
 *
 * Return: none
 */
void
struct_init (struct doc_struct *self, char *name)
{
	self->name = name;
	self->description = strdup ("");
	
	// Parameter
	self->members_amnt = 0;
	self->members[STRUCT_MEMBERS_NAME] = NULL;
	self->members[STRUCT_MEMBERS_DESC] = NULL;
}

/**
 * struct_free()
 * @self - The structure itself.
 *
 * Free's the allocated memory of a struct structure.
 *
 * Return: none
 */
void
struct_free (struct doc_struct *self)
{
	free (self->name);
	free (self->description);
	
	strlist_free (self->members, STRUCT_MEMBERS_LAST, self->members_amnt);
}

/**
 * struct_member_insert()
 * @self - The struct object itself.
 * @name - Name of the member.
 * @description - Description of the member.
 *
 * Insert a new member to the struct.
 *
 * Return: none
 */
void
struct_member_insert (struct doc_struct *self, char *name, char *description)
{
	self->members[STRUCT_MEMBERS_NAME] = strlist_insert (self->members[STRUCT_MEMBERS_NAME],
								name, ++self->members_amnt);
						    
	self->members[STRUCT_MEMBERS_DESC] = strlist_insert (self->members[STRUCT_MEMBERS_DESC],
								description, self->members_amnt); 
}
