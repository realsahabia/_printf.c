#include "main.h"
/**
 * print_int - Print int
 * @args: Lista of arguments
 *
 * Return: Number of ints printed
 */
int print_int(va_list args)
{
    int count = 0;

    int integer = va_arg(args, int);

    char buffer[20];
    int length = 0;

    if (integer == 0) {
        buffer[length++] = '0';
    } else {
        if (integer < 0) {
            buffer[length++] = '-';
            integer = -integer;
        }

        int temp = integer;
        while (temp != 0) {
            temp /= 10;
            length++;
        }

        int index = length - 1;
        while (integer != 0) {
            int digit = integer % 10;
            buffer[index--] = '0' + digit;
            integer /= 10;
        }
    }

    int result = write(1, buffer, length);
    if (result >= 0)
        count += result;

    return count;
}
