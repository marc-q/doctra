/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include <string.h>
#include "strlist.h"
#include "object.h"

/**
 * object_init()
 * @self - The structure itself.
 *
 * Initialize's a doc_object structure.
 *
 * Return: none
 */
void
object_init (struct doc_object *self)
{
	self->description = strdup ("");
	self->returns = NULL;
	
	// Members
	self->members_amnt = 0;
	self->members[OBJ_MEMBERS_NAME] = NULL;
	self->members[OBJ_MEMBERS_DESC] = NULL;
}

/**
 * object_free()
 * @self - The structure itself.
 *
 * Free's the allocated memory of a doc_object structure.
 *
 * Return: none
 */
void
object_free (struct doc_object *self)
{
	free (self->description);
	
	if (self->returns != NULL)
	{
		free (self->returns);
	}
	
	if (self->members_amnt != 0)
	{
		strlist_free (self->members, OBJ_MEMBERS_LAST, self->members_amnt);
	}
}

/**
 * object_member_insert()
 * @self - The structure itself.
 * @name - Name of the member.
 * @description - Description of the member.
 *
 * Insert a new member to the doc_object.
 *
 * Return: none
 */
void
object_member_insert (struct doc_object *self, char *name, char *description)
{
	self->members[OBJ_MEMBERS_NAME] = strlist_insert (self->members[OBJ_MEMBERS_NAME],
								name, ++self->members_amnt);
						    
	self->members[OBJ_MEMBERS_DESC] = strlist_insert (self->members[OBJ_MEMBERS_DESC],
								description, self->members_amnt); 
}
