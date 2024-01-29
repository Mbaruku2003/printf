#include "main.h"
#include <unistd.h>
/**
 * r - prints a string in reverse
 * @format: sormat of the string
 * Return: 0
 */
int r(const char *format, ...)
{
	va_list folder;
	int count = 0;
	int i;
	int length;

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
			else if (*format == 'r')
			{
				char *str = va_arg(folder, char*);

				for (i = 0; str[i] != '\0'; i++)
				{
					length++;
				}
				for (i = length - 1; str[i] >= 0; i++)
				{
					write(1, str--, 1);
					count++;
				}
			}
		}
		format++;
	}
	va_end(folder);
	return (count);
}
