# BeeProjects_Printf
Here is my attempt at recreating the printf function from C. 

This function should successfully mimic the library printf function and convert %c, %s, %p, %d, %i, %u, %x, %X and %%(print the percent sign). In my ft_printf, I have decided that if the character behind is not one of the cspdiuxX%, it will just print out the character.

for example:
Library printf
printf("Hello World %d", 5);
Hello World 5
My printf
ft_printf("Hello World %d", 5);
Hello World 5

My approach is going through each character of the string argument that was passed through. If it's not a % sign, it writes the char. If it is a % then we assess what is after it and decide which function to go to get the right output. 

c = a char
s = a string
p = a pointer
d & i = integer
u = unsigned integer
x & X = hex but with capitalized letter in it.

*The extrenal functions that we are allowed to use in this project are malloc, free, write, va_start, va_arg, va_copy, and va_end. 
