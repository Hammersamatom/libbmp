CC = g++
OBJECTS = ../libbmp.cpp test.cpp
LIBS =
CFLAGS = -Wall -Werror -Wextra -O2
BINDIR = $(DESTDIR)/usr/bin
NAME = test

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)

clean:
	rm $(NAME)
