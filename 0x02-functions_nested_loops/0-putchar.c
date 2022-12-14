#include "holy.h"

/**
 * main - debugging example
 * Return: 0
 */
int main(void)
{
        char *holy = "Holy";

        while (*holy)
        {
                _putchar(*holy);
                holy++;
        }
        _putchar('\n');
        return (0);

