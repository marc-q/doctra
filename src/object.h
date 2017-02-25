#ifndef __DOCTRA_OBJECT_H__
#define __DOCTRA_OBJECT_H__

enum object_members
{
	OBJ_MEMBERS_NAME = 0,
	OBJ_MEMBERS_DESC,
	OBJ_MEMBERS_LAST
};

/**
 * struct doc_object
 * @members_amnt - Amount of entries in the string list.
 * @description - Description of the object.
 * @returns - Description of what the object returns.
 * @members - String list storing the members.
 *
 * Stores the documentation informations.
 */
struct doc_object
{
	size_t members_amnt;
	char *description;
	char *returns;
	char **members[OBJ_MEMBERS_LAST];
};

void object_init (struct doc_object*);
void object_free (struct doc_object*);

void object_member_insert (struct doc_object*, char*, char*);

#endif /* __DOCTRA_OBJECT_H__ */

