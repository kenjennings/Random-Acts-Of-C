# Random-Acts-Of-C
Misc utilities and functions

DEBLANK: 
Remove leading, and trailing blanks from a string. 
This assumes a natural C string ending in the appropriate terminator.
Updates are done in-place to the string passed as argument, so no memory allocation.
int deblank( char * s )
