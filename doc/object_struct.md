doc_struct
===========
Represents a struct.


**Members**

**Name** | **Description**
-------- | ---------------
members_amnt | Amount of members.
name | Name of the struct.
description | Description of the struct.
members | A string list holding the members.


struct_init
===========
Initialize's a doc_struct structure.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.
name | The name of the struct.

**Returns**
none

struct_free
===========
Free's the allocated memory of a struct structure.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.

**Returns**
none

struct_member_insert
====================
Insert a new member to the struct.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | The struct object itself.
name | Name of the member.
description | Description of the member.

**Returns**
none

