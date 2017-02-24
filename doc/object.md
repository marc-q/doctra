doc_object
===========
A linked list of objects.


**Members**

**Name** | **Description**
-------- | ---------------
type | Type of the object.
element | Data of the object.
next | Address of the next entry.


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

