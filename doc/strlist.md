#strlist_insert
Inserts an entry into a string list.

**Parameters**

**Name** | **Description**
-------- | ---------------
strlist | String list to modify.
str | String to add to the string list.
len | Amount of entries in the string list (including this one).

**Returns**
The new address of @strlist.

#strlist_free
Frees a string list if it has entries.

**Parameters**

**Name** | **Description**
-------- | ---------------
strlist | String list to free.
items | Amount of items in the string list.
len | Amount of entries in the string list.

**Returns**
none
