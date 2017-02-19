function_init
=============
Initialize's a doc_function structure.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.
name | The name of the function.

**Returns**
none

function_free
=============
Free's the allocated memory of a function structure.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.

**Returns**
none

function_arg_insert
===================
Insert a new argument/parameter to the function.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | The function object itself.
name | Name of the argument.
description | Description of the argument.

**Returns**
none

object_append
=============
Append's an entry to the linked list.


**Parameters**

**Name** | **Description**
-------- | ---------------
list | List head.
type | The type of the element.
element | The element.

**Returns**
Pointer to the list head.

object_free
===========
Free's the whole linked list.


**Parameters**

**Name** | **Description**
-------- | ---------------
list | List head.

**Returns**
none
