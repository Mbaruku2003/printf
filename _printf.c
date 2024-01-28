#include <unistd.h>
#include "main.h"
/**
 * _printf -function that produce output according to a format
 * @format: pointeer to variable in main.c
 *Return 0
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
			else if(*format == 'c')
			{
				char letter = va_arg(folder, int);
				write (1, &letter, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(folder, char *);
				if (str == NULL)
				{
					write(1, "NULL", 6);
					count++;
				}
			}
			else if (*format == '%')
			{
				write (1, format, 1);
				count++;
			}

		}
		format++;
}
printf("\n");
va_end(folder);
return (*format);
}
