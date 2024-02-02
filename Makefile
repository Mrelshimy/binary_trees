CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM = rm
DEPS = 0-*.c 1-*.c 2-*.c 3-*.c binary_tree_print.c


%.out: tests/%.c
	$(CC) $(CFLAGS) *.c $< -o $@

%: tests/%.c
	$(CC) $(CFLAGS) $(DEPS) $@-*.c $< -o $@.out
	@ echo "\noutput of running ./$@.out\n****************************"
	@ ./$@.out

leakcheck: $(N).out
	valgrind --track-origins=yes --leak-check=full -s ./$<

clean:
	$(RM) -f *~ *.out
