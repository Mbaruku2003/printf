#include "main.h"
#include <unistd.h>
/**
 * _printf: entry point
 * @formst: the frmat used
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	char leo;

	while ((leo = *format++) != '\0')
	{
		if (leo == %)
		{
			leo = *format++;
			switch (leo)
			{
				case 'c':
					leo = va_arg(args, int);
					write (1, &leo, 1);
					count++;
					break;
				case 's':
					char *mbaruk = va_arg(args, char *);
					while (*mbaruk)
					{
						write(1, str++, 1);
						count++;
					}
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, &leo, 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, &leo, 1);
			count++;
		}
	}
	}
	va_end(args);
	return (count);
}
