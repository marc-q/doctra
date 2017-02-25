doc_node
========
A linked list of objects.

**Members**

**Name** | **Description**
-------- | ---------------
type | Type of the node.
element | Data of the node.
name | Name of the node;
next | Address of the next entry.


node_init
=========
Initializes a node structure and its element.

**Parameters**

**Name** | **Description**
-------- | ---------------
self | Node to initialize.
type | Type of the node.
name | Name of the node.

**Returns**
none

node_append
===========
Appends an entry to the linked list.

**Parameters**

**Name** | **Description**
-------- | ---------------
list | List head.
type | Type of the node.
element | The element.

**Returns**
Pointer to the list head.

node_free
=========
Frees the whole linked list.

**Parameters**

**Name** | **Description**
-------- | ---------------
list | List head.

**Returns**
none

