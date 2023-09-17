#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h> /* Include ctype.h for toupper */
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Prints formatted output
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
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
                    int divisor = 1;
                    
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
                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    int binary[32];
                    int i = 0;
		    int j;

                    if (num == 0)
                    {
                        _putchar('0');
                        count++;
                    }
                    else
                    {
                        while (num > 0)
                        {
                            binary[i++] = num % 2;
                            num /= 2;
                        }
                        for (j = i - 1; j >= 0; j--)
                        {
                            _putchar('0' + binary[j]);
                            count++;
                        }
                    }
                    break;
                }
                case 'r':
                {
                    char *str = va_arg(args, char *);
                    int len = 0;
		    int i;
		    if (str == NULL)
		        str = ")llun(";

                    while (str[len])
                        len++;

                    for (i = len - 1; i >= 0; i--)
                    {
                        _putchar(str[i]);
                        count++;
                    }
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    unsigned int divisor = 1;
                    
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
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    unsigned int octal[32];
                    int i = 0;
		    int j;

                    if (num == 0)
                    {
                        _putchar('0');
                        count++;
                    }
                    else
                    {
                        while (num > 0)
                        {
                            octal[i++] = num % 8;
                            num /= 8;
                        }
                        for (j = i - 1; j >= 0; j--)
                        {
                            _putchar('0' + octal[j]);
                            count++;
                        }
                    }
                    break;
                }
                case 'x':
                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char hex[16];
                    int i = 0;
		    int j;
                    char hex_digits[] = "0123456789abcdef";

                    if (num == 0)
                    {
                        _putchar('0');
                        count++;
                    }
                    else
                    {
                        while (num > 0)
                        {
                            hex[i++] = hex_digits[num % 16];
                            num /= 16;
                        }
                        for (j = i - 1; j >= 0; j--)
                        {
                            if (*format == 'X')
                                _putchar(toupper(hex[j]));
                            else
                                _putchar(hex[j]);
                            count++;
                        }
                    }
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(args, void *);
                    unsigned long int address = (unsigned long int)ptr;
                    char hex[16];
                    int i = 0;
		    int j;
                    char hex_digits[] = "0123456789abcdef";

                    _putchar('0');
                    _putchar('x');
                    count += 2;

                    if (address == 0)
                    {
                        _putchar('0');
                        count++;
                    }
                    else
                    {
                        while (address > 0)
                        {
                            hex[i++] = hex_digits[address % 16];
                            address /= 16;
                        }
                        for (j = i - 1; j >= 0; j--)
                        {
                            _putchar(hex[j]);
                            count++;
                        }
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
