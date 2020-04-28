CC := gcc
CFLAGS := -ggdb -O0 -std=c99 -D_DEFAULT_SOURCE -Wall -Werror

TESTS := test_empty_graph test_insert_one_node test_create_one_node
TESTS += test_allocator test_find_one_node test_parse_single_node
TESTS += test_parse_single_node_nonewline

all:

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

test_%: tests/%.o src/graph.o src/allocator.o src/parser.o
	$(CC) -o $@ $^

test: $(TESTS)
	@for test in $(TESTS); do \
	    printf "%-40s: " "$$test"; ./$$test; \
	done

clean:
	rm -f *.o src/*.o *~ src/*~
	rm -f test_* tests/*.o

.PHONY: all clean
