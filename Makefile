CC = gcc
OBJECTS = src/strlist.c src/config.c src/objects/object_function.c src/object.c src/parser.c src/exports/export_md.c doctra.c
LIBS =
CFLAGS = -Wall -Wextra -O2
BINDIR = $(DESTDIR)/usr/bin
NAME = doctra

doctra: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	rm $(NAME)
