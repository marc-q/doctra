/* Copyright 2017 Marc Volker Dickmann
 * Project: Doctra
 */
#include <stdio.h>
#include "src/config.h"
#include "src/object.h"
#include "src/node.h"
#include "src/parser.h"
#include "src/exports/export_md.h"

int
main (int argc, char *argv[])
{
	if (argc == 3)
	{
		struct doc_config conf;
		config_init (&conf);
		
		struct doc_node *nodes = NULL;
		nodes = parse_file (&conf, nodes, argv[1]);
		
		export_md (nodes, argv[2]);
		
		config_free (&conf);
		node_free (nodes);
	}
	else
	{
		printf ("Usage: %s <filename_src> <filename_out>!\n", argv[0]);
	}
	return 0;
}
