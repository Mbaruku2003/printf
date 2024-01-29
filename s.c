#include "main.h"
#include <unistd.h>
/**
 * _printf - print character with %c
 *@format: argument passed
 *Return: always 1
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int i;
	int length = 0;
	va_list folder;

	if (format == NULL || format[0] == '\0')
		return (-1);
	va_start(folder, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == 's')
			{
				char *str = va_arg(folder, char *);


				if (str == NULL)
					write(1, "NULL", 5);
				else
				for (i = 0; str[i]; i++)
					while (*str && length++)
					{
						write(1, str++, 1);
						count++;
					}
			}
		}
		format++;
	}
	va_end(folder);
	return (count);
}
