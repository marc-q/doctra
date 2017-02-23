/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include "strlist.h"

/**
 * strlist_insert()
 * @strlist - String list to modify.
 * @str - String to add to the string list.
 * @len - Amount of entries in the string list (including this one).
 *
 * Inserts an entry into a string list.
 *
 * Return: The new address of strlist.
 */
char**
strlist_insert (char **strlist, char *str, const size_t len)
{
	strlist = realloc (strlist, sizeof (char**) * len);
	strlist[len - 1] = str;
	return strlist;
}

/**
 * strlist_free()
 * @strlist - String list to free.
 * @items - Amount of items in the string list.
 * @len - Amount of entries in the string list.
 *
 * Frees a string list if it has entries.
 *
 * Return: none
 */
void
strlist_free (char ***strlist, const size_t items, const size_t len)
{
	if (len <= 0)
	{
		// No item to free
		return;
	}
	
	// Free the strings
	size_t i = 0, l = 0;
	while (i < items)
	{
		if (l >= len)
		{
			l = 0;
			i++;
		}
		else
		{
			free (strlist[i][l++]);
		}
	}
	
	// Free the ptrs
	for (i = 0; i < items; i++)
	{
		free (strlist[i]);
	}
}
