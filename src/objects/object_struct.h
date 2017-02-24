#ifndef __DOCTRA_OBJECT_STRUCT_H__
#define __DOCTRA_OBJECT_STRUCT_H__

enum struct_members
{
	STRUCT_MEMBERS_NAME = 0,
	STRUCT_MEMBERS_DESC,
	STRUCT_MEMBERS_LAST
};

/**
 * struct doc_struct
 * @members_amnt - Amount of members.
 * @name - Name of the struct.
 * @description - Description of the struct.
 * @members - A string list holding the members.
 *
 * Represents a struct.
 */
struct doc_struct
{
	size_t members_amnt;
	char *name;
	char *description;
	char **members[STRUCT_MEMBERS_LAST];
};

void struct_init (struct doc_struct*, char*);
void struct_free (struct doc_struct*);

void struct_member_insert (struct doc_struct*, char*, char*);

#endif /* __DOCTRA_OBJECT_STRUCT_H__ */
