				my_malloc
SYNOPSIS
-----------

The my_malloc is an implementation of C's malloc and free functions. It is used
to understand how the memory allocator works by creating a heap of a certain
size and finding an amount of space that user requested to set a size for the
user to use and to prevent misalignment. After allocating, if the user decides
to free it, it must check if the previous and next blocks of memory are free to
merge them together to prevent fragmentation. 

DESCRIPTION
-----------

The my_malloc function is used to allocate how much the user wants from the
heap. It adds a header and a footer as pointers to know if it is allocated and
8-bit aligned. This is to know where the user is in the heap and keep track of
which block are allocated or free. This is used to prevent confliction with
another allocated block in the heap the next time the user call my_malloc.

The my_free function is used to check if the block where the user wants to free
from the heap to make it avaliable to use again with my_malloc. It needs to
check whether the previous and next block is free in order to merge it as one
free block to prevent the allocator from having false fragmentation despite
having enough free space.

EXAMPLES
-----------

The driver.c file is used to explain how the my_malloc and my_free function
works. The sentence is the input from the user. It creates two heap called p
and q. Then, each character from the sentence is added into
the heap p. When the driver prints p, it is the same sentence and when the
location of q is the next address after p. For this case, the sentence is 0x20
bigger. Next is to test when the argument for my_malloc is zero, first is to
free p so it no longer hold the sentence and then call it again but with 0 as
the argument for my_malloc this time. It will print "Zero Input" since nothing 
is in p. Next example is to test when the argument is too big, put in 1000000
as the argument for my_malloc. It will print "Error Condition" since the size
requested is bigger than the heap size so it cause the ENOMEM error.

AUTHOR
-----------

Guo Jing Wu
