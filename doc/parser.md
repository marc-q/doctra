# parse_object
Parses fields of a doc_object.

**Parameters**

**Name** | **Description**
-------- | ---------------
self | The object to insert the data.
cursor | String to parse.

**Returns**
none

# parse_node
Parses a node type and initialize it.

**Parameters**

**Name** | **Description**
-------- | ---------------
node | Node to store the object in.
cursor | String to parse.

**Returns**
none

# parse_file
Parses a source file and returns a doc_node linked list
which contains the information gathered from the source file.

**Parameters**

**Name** | **Description**
-------- | ---------------
conf | The configuration.
nodes | The list head.
filename | Name of the source file.

**Returns**
A linked list containing the information.
