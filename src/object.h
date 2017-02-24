#ifndef __DOCTRA_OBJECT_H__
#define __DOCTRA_OBJECT_H__

union doc_element
{
	struct doc_function func;
};

enum element_type
{
	DOC_ELEMENT_NONE = 0,
	DOC_ELEMENT_FUNCTION
};

struct doc_object
{
	enum element_type type;
	union doc_element element;
	struct doc_object *next;
};

struct doc_object* object_append (struct doc_object*, const enum element_type, const union doc_element*);

void object_free (struct doc_object*);

#endif /* __DOCTRA_OBJECT_H__ */
