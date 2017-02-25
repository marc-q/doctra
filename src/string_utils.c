/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string_utils.h"

/**
 * string_match_start()
 * @str - String to search in.
 * @pat - Pattern to search for.
 *
 * Checks if the string @str starts with
 * the pattern @pat.
 *
 * Return: If the pattern is found true, otherwise false.
 */
bool
string_match_start (const char *str, const char *pat)
{
	const size_t pat_len = strlen (pat);
	
	return (strlen (str) >= pat_len &&
		strncmp (str, pat, pat_len) == 0);
}

/**
 * string_match_end()
 * @str - String to search in.
 * @pat - Pattern to search for.
 *
 * Checks if the string @str ends with
 * the pattern @pat.
 *
 * Return: If the pattern is found true, otherwise false.
 */
bool
string_match_end (const char *str, const char *pat)
{
	const size_t str_len = strlen (str);
	const size_t pat_len = strlen (pat);
	
	return (str_len > pat_len &&
		strncmp (&str[str_len - pat_len], pat, pat_len) == 0);
}

/**
 * string_recat()
 * @dest - Destination.
 * @src - String to append.
 *
 * Allocates the memory needed to append @src to @dest
 * and append @src to @dest.
 *
 * Return: Location of @dest.
 */
char*
string_recat (char *dest, const char *src)
{
	dest = realloc (dest, (strlen (dest) + strlen (src) + 1) * sizeof (char));
	strcat (dest, src);
	return dest;
}

/**
 * strspan_c()
 * @str - String.
 * @end - End sequence.
 *
 * A simple shortcut.
 *
 * The returned string should be freed with free().
 *
 * Return: A new allocated substring of @str that ends at @end.
 */
char*
strspan_c (const char *str, const char *end)
{
	return strndup (str, (size_t)(strstr (str, end) - str));
}

/**
 * strspan()
 * @str - String to search.
 * @start - Start sequence.
 * @end - End sequence.
 *
 * Cuts the part between @start and @end out of
 * the string @str and paste it into allocated memory.
 *
 * The returned string should be freed with free().
 *
 * Return: A new allocated substring of @str.
 */
char*
strspan (const char *str, const char *start, const char *end)
{
	return strspan_c (&strstr (str, start)[strlen (start)], end);
}
