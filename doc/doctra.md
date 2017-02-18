print_spn
=========

**Parameters**

**Name** | **Description**
-------- | ---------------
str | The content.
start | Print from.
end | Print until.
f | Stream to print on.
Print's a substring of str into f.

**Returns**
none
print_spnc
==========

**Parameters**

**Name** | **Description**
-------- | ---------------
str | The content.
end | Print until the location of this substring.
f | Stream to print on.
Print's a substring of str into f.
Uses a substring to determine the end position.

**Returns**
none
print_spnc_underline
====================

**Parameters**

**Name** | **Description**
-------- | ---------------
str | The content.
end | Print until the location of this substring.
c | Character which will be used to create the underline.
f | Stream to print on.
The same a print_spnc, but with an addional underline.

**Returns**
none
parse_file
==========

**Parameters**

**Name** | **Description**
-------- | ---------------
filename_src | Filename of the source code.
filename_doc | Filename of the documentation.
Parses a file containing source code and docstrings
and writes a documentation in markdown to filename_doc.

**Returns**
none
