CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM = rm


%.out: tests/%.c
	$(CC) $(CFLAGS) *.c $< -o $@

%: tests/%.c
	$(CC) $(CFLAGS) *.c $< -o $@.out

leakcheck: $(N).out
	valgrind --track-origins=yes --leak-check=full -s ./$<

clean:
	$(RM) -f *~ *.out
