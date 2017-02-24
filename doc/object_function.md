doc_function
=============
Represents a function.


**Members**

**Name** | **Description**
-------- | ---------------
args_amnt | Amount of arguments.
name | Name of the function.
description | Description of the function.
returns | Description of what the function returns.
args | A string list holding the arguments.


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

