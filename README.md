# buffers

An implementation of dynamic buffers, both generic integer and characters.

## Rationale

I wanted to use something like [Sean's toolbox's stretchy
buffers](https://github.com/nothings/stb), but I was frustrated by the
possible alignment issues and undefined behavior.  So I wrote this.

## Buffer

This is a dynamically expanding buffer of uint32_t.  This allows you to
store references into other arrays and/or other information by encoding
it into the bits.  One could implement a priority queue, for example,
with the priority encoded in the upper 16 bits, and an index into an
array of objects in the lower 16.

The main feature of this buffer is the ability to change the storage
mechanism.  By implementing the `size` and `cap` macros, as well as a
grow function, these buffers will work on preallocated storage, or with
a separate metadata storage facility, etc.

## Cbuffer

This is a character buffer.  As of right now, it is explicitly allocated
on the heap, but this may change to something more flexible in the future.
The size and capacity are stored in the 4 bytes preceding the array
pointer, 2 bytes for each datum.  This is implemented without type
punning, and so should be safe and defined.  The idea with this is to
be used as expanding string storage, allowing one to simply pass around
an index into the array, and if some form of hashing is implemented,
strequals becomes simple numeric equality.  Representing strings as a
number has other benefits, like allowing the storage of the number along
with other data into the bits of a number in the previous buffers.

