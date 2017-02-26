string_match_start
==================
Checks if the string @str starts with
the pattern @pat.

**Parameters**

**Name** | **Description**
-------- | ---------------
str | String to search in.
pat | Pattern to search for.

**Returns**
If the pattern is found true, otherwise false.

string_match_end
================
Checks if the string @str ends with
the pattern @pat.

**Parameters**

**Name** | **Description**
-------- | ---------------
str | String to search in.
pat | Pattern to search for.

**Returns**
If the pattern is found true, otherwise false.

string_recat
============
Allocates the memory needed to append @src to @dest
and append @src to @dest.

**Parameters**

**Name** | **Description**
-------- | ---------------
dest | Destination.
src | String to append.

**Returns**
Location of @dest.

string_cut_end
==============
Builds a new string containing @str
without the @end string.
This should be faster than strspan_c.
The returned string should be freed with free().

**Parameters**

**Name** | **Description**
-------- | ---------------
str | String.
end | End sequence to remove.

**Returns**
A new allocated string.

strspan_c
=========
A simple shortcut.
The returned string should be freed with free().

**Parameters**

**Name** | **Description**
-------- | ---------------
str | String.
end | End sequence.

**Returns**
A new allocated substring of @str that ends at @end.

strspan
=======
Cuts the part between @start and @end out of
the string @str and paste it into allocated memory.
The returned string should be freed with free().

**Parameters**

**Name** | **Description**
-------- | ---------------
str | String to search.
start | Start sequence.
end | End sequence.

**Returns**
A new allocated substring of @str.
