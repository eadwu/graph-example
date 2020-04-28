#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

typedef struct FreeBlock *FreeBlock;

struct FreeBlock {
    FreeBlock next;
};

typedef struct Allocator {
    size_t size;
    FreeBlock blocks;
} *Allocator;

Allocator allocator_create(size_t size);
void *allocator_alloc(Allocator a);
void allocator_free(Allocator a, void *ptr);

#endif /* ALLOCATOR_H */
