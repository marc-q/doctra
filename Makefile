CC = gcc
OBJECTS = src/strlist.c src/string_utils.c src/config.c src/object.c src/node.c src/parser.c src/exports/export_md.c doctra.c
LIBS =
CFLAGS = -Wall -Wextra -O2
BINDIR = $(DESTDIR)/usr/bin
NAME = doctra

doctra: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	rm $(NAME)
