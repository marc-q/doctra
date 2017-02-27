#doc_object
Stores the documentation informations.

**Members**

**Name** | **Description**
-------- | ---------------
members_amnt | Amount of entries in the string list.
description | Description of the object.
returns | Description of what the object returns.
members | String list storing the members.


#object_init
Initialize's a doc_object structure.

**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.

**Returns**
none

#object_free
Free's the allocated memory of a doc_object structure.

**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.

**Returns**
none

#object_member_insert
Insert a new member to the doc_object.

**Parameters**

**Name** | **Description**
-------- | ---------------
self | The structure itself.
name | Name of the member.
description | Description of the member.

**Returns**
none
