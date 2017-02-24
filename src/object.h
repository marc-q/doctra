#ifndef __DOCTRA_OBJECT_H__
#define __DOCTRA_OBJECT_H__

union doc_element
{
	struct doc_function func;
	struct doc_struct struc;
};

enum element_type
{
	DOC_ELEMENT_NONE = 0,
	DOC_ELEMENT_FUNCTION,
	DOC_ELEMENT_STRUCT
};

/**
 * struct doc_object
 * @type - Type of the object.
 * @element - Data of the object.
 * @next - Address of the next entry.
 *
 * A linked list of objects.
 */
struct doc_object
{
	enum element_type type;
	union doc_element element;
	struct doc_object *next;
};

struct doc_object* object_append (struct doc_object*, const enum element_type, const union doc_element*);

void object_free (struct doc_object*);

#endif /* __DOCTRA_OBJECT_H__ */
