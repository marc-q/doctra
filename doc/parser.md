strspn_c
========
A simple shortcut.


**Parameters**

**Name** | **Description**
-------- | ---------------
str | String.
end | Ending sequence.

**Returns**
a new allocated substring of @str that ends at @end.

parse_file
==========
Parses a source file and returns a doc_object linked list
which contains the information gathered from the source file.


**Parameters**

**Name** | **Description**
-------- | ---------------
conf | The configuration.
objs | The list head.
filename | Name of the source file.

**Returns**
A linked list containing the information.
