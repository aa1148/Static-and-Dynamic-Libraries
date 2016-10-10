# Static-and-Dynamic-Libraries
Included are two libraries: A Static library (.h) with functions to convert from a string of characters in different formats (binary, floating point, hexadecimal) to the actual real value, and a Dynamic library (.dll) with a function that will read an extremely large string, allocating memory as the string demands it.

To use the Static library, include in your program the file, as follows: #include "convert.h"
This library contains the functions:
- int asciiBinaryToInt(char *cArr)
- int asciiHEXToInt(char *cArr)
- double asciiToDouble(char *cArr)

If the input char array contains any invalid characters, partial results up to the invalid character will be returned.

To use the Dynamic library, include in your program the file, as follows: #include "extremelyLargeString.dll"
This library contains the function:
- DllExport char* extremelyLargeString()

An example of how to use it in your program would be:
char* myString = extremelyLargeString();

This will ask for input from the user, and the input will only end when the user enters the asterisk (*) character.
