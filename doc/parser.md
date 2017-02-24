

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

parse_function
==============
Parses fields of a function object.


**Parameters**

**Name** | **Description**
-------- | ---------------
conf | The configuration.
func | Function object.
cursor | String to parse.

**Returns**
none

parse_struct
============
Parses fields of a struct object.


**Parameters**

**Name** | **Description**
-------- | ---------------
conf | The configuration.
struc | Struct object.
cursor | String to parse.

**Returns**
none

parse_object
============
Parses a object type and initialize it.


**Parameters**

**Name** | **Description**
-------- | ---------------
conf | The configuration.
fields | Element object.
type | The object type will be stored here.
cursor | String to parse.

**Returns**
none

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

