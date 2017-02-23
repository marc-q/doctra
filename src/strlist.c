/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include "strlist.h"

/**
 * strlist_insert()
 * @strlist - Stringlist to modify.
 * @str - String to add to the stringlist.
 * @len - Amount of entrys in the stringlist (including this one).
 *
 * Insert's a entry to a stringlist.
 *
 * Return: The new address of stringlist;
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
 * @strlist - Stringlist to free.
 * @items - Amount of items in the strlist.
 * @len - Amount of entry's in the strlist.
 *
 * Free's a stringlist if it has entry's.
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
