/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include "src/config.h"
#include "src/object.h"
#include "src/parser.h"
#include "src/export_md.h"

int
main (int argc, char *argv[])
{
	if (argc == 3)
	{
		struct doc_config conf;
		
		config_init (&conf);
		
		struct doc_object *objs = NULL;
		objs = parse_file (&conf, objs, argv[1]);
		
		export_md (objs, argv[2]);
		
		config_free (&conf);
		object_free (objs);
	}
	else
	{
		printf ("Usage: %s <filename_src> <filename_out>!\n", argv[0]);
	}
	return 0;
}
