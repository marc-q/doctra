/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * print_spn()
 * @str - The content.
 * @start - Print from.
 * @end - Print until.
 * @f - Stream to print on.
 *
 * Print's a substring of str into f.
 *
 * Return: none
 */
static void
print_spn (const char *str, const size_t start, const size_t end, FILE *f)
{
	for (size_t i = start; i < end; i++)
	{
		fputc (str[i], f);
	}
}

/**
 * print_spnc()
 * @str - The content.
 * @end - Print until the location of this substring.
 * @f - Stream to print on.
 *
 * Print's a substring of str into f.
 * Uses a substring to determine the end position.
 *
 * Return: none
 */
static void
print_spnc (const char *str, const char *end, FILE *f)
{
	const size_t pos_end = strstr (str, end) - str;
	
	print_spn (str, 0, pos_end, f);
}

/**
 * print_spnc_underline()
 * @str - The content.
 * @end - Print until the location of this substring.
 * @c - Character which will be used to create the underline.
 * @f - Stream to print on.
 *
 * The same a print_spnc, but with an addional underline.
 *
 * Return: none
 */
static void
print_spnc_underline (const char *str, const char *end, const char c, FILE *f)
{
	const size_t pos_end = strstr (str, end) - str;
	
	print_spn (str, 0, pos_end, f);
	fputc ('\n', f);
	
	for (size_t i = 0; i < pos_end; i++)
	{
		fputc (c, f);
	}
	fputc ('\n', f);
}

/**
 * parse_file()
 * @filename_src - Filename of the source code.
 * @filename_doc - Filename of the documentation.
 *
 * Parses a file containing source code and docstrings
 * and writes a documentation in markdown to filename_doc.
 *
 * Return: none
 */
static void
parse_file (const char *filename_src, const char *filename_doc)
{
	FILE *f_src = fopen (filename_src, "r");
	if (f_src == NULL)
	{
		return;
	}
	
	FILE *f_doc = fopen (filename_doc, "w");
	if (f_doc == NULL)
	{
		fclose (f_src);
		return;
	}
	
	char line[250];
	const char *cursor;
	bool mode = false;
	bool argtable = false;
	
	while (fgets (line, sizeof (line), f_src) != NULL)
	{	
		// Enter the documentation mode
		if (!mode && strstr (line, "/**") != NULL)
		{
			mode = true;
		}
		// Exit the documentation mode
		else if (mode && strstr (line, "*/") != NULL)
		{
			argtable = false;
			mode = false;
		}
		else if (mode)
		{
			cursor = strstr (line, "* ");
			
			if (cursor == NULL)
			{
				continue;
			}
			
			cursor += 2;
			
			// Argument
			if (cursor[0] == '@')
			{
				// Print the table only once!
				if (!argtable)
				{
					fputs ("\n**Parameters**\n\n", f_doc);
					fputs ("**Name** | **Description**\n", f_doc);
					fputs ("-------- | ---------------\n", f_doc);
					argtable = true;
				}
				print_spnc (cursor + 1, " -", f_doc);
				fputs (" | ", f_doc);
				print_spnc (strstr (cursor, "- ") + 2, "\n", f_doc);
				fputc ('\n', f_doc);
			}
			// Function name
			else if (strstr (cursor, "()") != NULL)
			{
				print_spnc_underline (cursor, "()", '=', f_doc);
			}
			// Return
			else if (strncmp (cursor, "Return:", strlen ("Return:")) == 0)
			{
				fputs ("\n**Returns**\n", f_doc);
				print_spnc (cursor + (strlen ("Return: ")), "\n", f_doc);
				fputc ('\n', f_doc);
			}
			// Function description
			else
			{
				print_spnc (cursor, "\n", f_doc);
				fputc ('\n', f_doc);
			}
		}
	}
	
	fclose (f_src);
	fclose (f_doc);
}

int
main (int argc, char *argv[])
{
	if (argc == 3)
	{
		parse_file (argv[1], argv[2]);
	}
	else
	{
		printf ("Usage: %s <filename_src> <filename_out>!\n", argv[0]);
	}
	return 0;
}
