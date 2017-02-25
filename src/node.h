#ifndef __DOCTRA_NODE_H__
#define __DOCTRA_NODE_H__

enum node_type
{
	DOC_NODE_NONE = 0,
	DOC_NODE_FUNCTION,
	DOC_NODE_STRUCT
};

/**
 * struct doc_node
 * @type - Type of the node.
 * @element - Data of the node.
 * @name - Name of the node;
 * @next - Address of the next entry.
 *
 * A linked list of objects.
 */
struct doc_node
{
	enum node_type type;
	struct doc_object element;
	char *name;
	struct doc_node *next;
};

void node_init (struct doc_node*, const enum node_type, char*);
struct doc_node* node_append (struct doc_node*, const struct doc_node*);
void node_free (struct doc_node*);

#endif /* __DOCTRA_NODE_H__ */
