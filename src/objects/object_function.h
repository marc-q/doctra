#ifndef __DOCTRA_OBJECT_FUNCTION_H__
#define __DOCTRA_OBJECT_FUNCTION_H__

enum function_args
{
	FUNCTION_ARGS_NAME = 0,
	FUNCTION_ARGS_DESC,
	FUNCTION_ARGS_LAST
};

struct doc_function
{
	size_t args_amnt;
	char *name;
	char *description;
	char *returns;
	char **args[FUNCTION_ARGS_LAST];
};

void function_init (struct doc_function*, char*);
void function_free (struct doc_function*);

void function_arg_insert (struct doc_function*, char*, char*);

#endif /* __DOCTRA_OBJECT_FUNCTION_H__ */
