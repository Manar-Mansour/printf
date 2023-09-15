#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    int count = 0;
    int divisor = 1;
    va_list args;
    va_start(args, format);


    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
		    int i;
                    for (i = 0; str[i]; i++)
                    {
                        _putchar(str[i]);
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        _putchar('-');
                        count++;
                        num = -num;
                    }
                   
		    
                    while (num / divisor >= 10)
                    {
                        divisor *= 10;
                    }
                    while (divisor != 0)
                    {
                        _putchar('0' + num / divisor);
                        count++;
                        num %= divisor;
                        divisor /= 10;
                    }
                    break;
                }
                case '%':
                {
                    _putchar('%');
                    count++;
                    break;
                }
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
