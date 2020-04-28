#include <stdio.h>

#include "../src/allocator.h"

#define BLOCK_SIZE 32

int main(int argc, char *argv[])
{
    Allocator a = allocator_create(BLOCK_SIZE);

    if (a == NULL || a->size != BLOCK_SIZE || a->blocks != NULL) {
        puts("failed");
        return 1;
    }

    void *mem = allocator_alloc(a);
    if (mem == NULL || mem - (void *)a->blocks != BLOCK_SIZE) {
        puts("failed");
        return 1;
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        if (((char *)mem)[i] != 0) {
            puts("failed");
            return 1;
        }
    }

    FreeBlock b = a->blocks;
    allocator_free(a, mem);

    if (a->blocks != mem || a->blocks->next != b) {
        puts("failed");
        return 1;
    }

    puts("passed");
    return 0;
}
