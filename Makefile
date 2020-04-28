CC := gcc
CFLAGS := -ggdb -O0 -std=c99 -D_DEFAULT_SOURCE -Wall -Werror

all:

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o src/*.o *~ src/*~

.PHONY: all clean
