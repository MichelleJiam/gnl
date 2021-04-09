# gnl
42/Codam get_next_line, a modified getline function

**Note**:  
An improved implementation using linked lists that does not SEGFAULT on large buffer sizes is available in my extended C library, [libftx](https://github.com/MichelleJiam/libftx/tree/master/src/gnl).

## Description
`get_next_line()` is a function which returns a line read from a file descriptor, without the newline.  
The function returns 1 when a line has been read, 0 when end-of-file has been reached, and -1 on error.

The restrictions of the project are to only hand in 2 `.c` files, with a maximum of 5 functions in each.  
No external library is allowed, other than the ones required for `read`, `malloc`, and `free`.

This program fulfills the bonus requirements of:
- a single static variable
- handles multiple file descriptors

## Compilation
`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=x`  
`x` being how many bytes `read` should read at a time.
