#ifndef __DOCTRA_OBJECT_H__
#define __DOCTRA_OBJECT_H__

// DOC_FUNCTION

enum doc_args
{
	DOC_ARGS_NAME = 0,
	DOC_ARGS_DESC,
	DOC_ARGS_LAST
};

struct doc_function
{
	size_t args_amnt;
	char *name;
	char *description;
	char *returns;
	char **args[DOC_ARGS_LAST];
};

void function_init (struct doc_function*, char*);
void function_free (struct doc_function*);

void function_arg_insert (struct doc_function*, char*, char*);

// DOC_ELEMENT

union doc_element
{
	struct doc_function func;
};

enum element_type
{
	DOC_ELEMENT_FUNCTION = 0
};

// DOC_OBJECT

struct doc_object
{
	int type;
	union doc_element element;
	struct doc_object *next;
};

struct doc_object* object_append (struct doc_object*, const enum element_type, const union doc_element*);

void object_free (struct doc_object*);

#endif /* __DOCTRA_OBJECT_H__ */
