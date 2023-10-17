#include "main.h"

/**
 * _printf - a function that prints formatted output according to specifiers
 * @format: the output string to be printed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int ch_num = 0;
	char perc = '%';
	va_list pr;

	if (format == NULL)
		return (-1);

	va_start(pr, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ch_num++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, &perc, 1);
				ch_num++;
			}
			else if (*format == 'c')
			{
				char cha_r = va_arg(pr, int);

				write(1, &cha_r, 1);
				ch_num++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(pr, char *);

				write(1, str, strlen(str));
				ch_num += strlen(str);
			}
		}
		format++;
	}
	va_end(pr);
	return (ch_num);
}
