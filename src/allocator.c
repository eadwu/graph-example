#include <stdlib.h>
#include <string.h>

#include "allocator.h"

#define CHUNK_SIZE 4096

Allocator allocator_create(size_t size) {
    Allocator a;

    if (size < sizeof(FreeBlock)) {
        size = sizeof(FreeBlock);
    }

    a = calloc(1, sizeof(struct Allocator));
    a->size = size;

    return a;
}

static FreeBlock fetch_blocks(size_t size) {
    void *mem = malloc(CHUNK_SIZE);
    FreeBlock blocks = NULL;

    if (mem == NULL) {
        return NULL;
    }

    for (size_t off = 0; off < CHUNK_SIZE; off += size) {
        FreeBlock b = mem + off;
        b->next = blocks;
        blocks = b;
    }

    return blocks;
}

void *allocator_alloc(Allocator a) {
    FreeBlock b;

    if (a->blocks == NULL) {
        a->blocks = fetch_blocks(a->size);
        if (a->blocks == NULL) {
            return NULL;
        }
    }

    b = a->blocks;
    a->blocks = b->next;

    memset(b, 0, a->size);

    return (void *)b;
}

void allocator_free(Allocator a, void *ptr) {
    FreeBlock b = ptr;

    if (ptr == NULL) {
        return;
    }

    b->next = a->blocks;
    a->blocks = b;
}
