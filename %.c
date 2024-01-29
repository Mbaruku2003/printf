#include "main.h"
#include <unistd.h>
/**
 * _printf - print character with %c
 * @format: format passed
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list folder;
	int count = 0;

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
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
		}
		format++;
	}
	va_end(folder);
	return (count);
}
