#include "main.h"
#include <unistd.h>

/**
 * print_char - print character with %c
 *@wow: argument passed
 *Return: always 1
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list folder;

	if (format == NULL || format[0] == '\0')
	{
		return (-1);
	}
	va_start(folder, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format =='c')
			{
				char letter = va_arg(folder, int);
				write(1, &letter, 1);
			}
		}
		format++;

	}
	va_end(folder);
	return (count);
}
