This repository contains an implementation of the _printf function, which is a custom version of the standard C library printf function. The _printf function is designed to produce output according to a specified format.

Function Prototype

int _printf(const char *format, ...);

The _printf function takes a format string as its first argument, followed by optional additional arguments. It returns the number of characters printed, excluding the null byte used to end output to strings.

Task 1: Implement basic conversion specifiers %c, %s, and %%.

Handle each specifier separately and print the corresponding output.

Task 2: Implement conversion specifiers %d and %i.

Convert the integer argument to a string and print the resulting string.

Task 3: Implement custom conversion specifier %b to print an unsigned integer in binary format.

Convert the decimal integer to binary representation and print the resulting string.

Task 4: Implement conversion specifiers %u, %o, %x, and %X.

Convert the respective integer arguments to strings in the desired base and print the resulting strings.

Task 5: Implement custom conversion specifier %S to print a string with non-printable characters represented as \x followed by the ASCII code in hexadecimal.

Iterate through the string and replace non-printable characters with the desired representation.

Task 6: Implement conversion specifier %p to print a pointer address.

Cast the pointer argument to a suitable type and print its hexadecimal representation.

Task 7: Handle flag characters +, space, and # for non-custom conversion specifiers.

Modify the output format based on the presence of these flags.

Task 8: Handle length modifiers l and h for conversion specifiers %d, %i, %u, %o, %x, and %X.

Adjust the conversion process based on the length modifiers.

Task 9: Handle field width for non-custom conversion specifiers.

Format the output to occupy the specified width.

Task 10: Handle precision for non-custom conversion specifiers.

Limit the output length based on the specified precision.

Task 11: Handle flag character 0 for non-custom conversion specifiers.

Pad the output with zeros instead of spaces when the width is specified and the flag is present.

Task 12: Handle flag character - for non-custom conversion specifiers.

Left-align the output instead of right-aligning it when the width is specified and the flag is present.

Task 13: Implement custom conversion specifier %r to print a reversed string.

Iterate through the string in reverse order and print the characters.

Task 14: Implement custom conversion specifier %R to print a string transformed using the ROT13 substitution cipher.

 Apply the ROT13 cipher to each character in the string and print the transformed string.

Task 15: Optimize output by using a local buffer of 1024 characters and minimizing calls to the write function.

 Maintain a local buffer and flush its contents to the standard output only when necessary.

