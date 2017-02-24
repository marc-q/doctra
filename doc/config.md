doc_config
===========
Holds the configuration.


**Members**

**Name** | **Description**
-------- | ---------------
len_return | Length of the return pattern.
len_mdelim | Length of the mdelim pattern.
len_struct | Length of the struct pattern.
pattern | Customizable patterns.


config_init
===========
Initialize a config structure.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | Pointer to the structure to init.

**Returns**
none

config_free
===========
Free's the allocated memory of a config
structure.


**Parameters**

**Name** | **Description**
-------- | ---------------
self | Pointer to the structure to free.

**Returns**
none

