#include "../holberton.h"
/**
 * main - combined main file to test expected and custom and view results side by side
 * Return: Always 0
 */
int main(void)
    int len;
    int l2;

    len = printf("standard  |Let's try to printf a simple sentence.\n");
    l2 = _printf("custom    |Let's try to printf a simple sentence.\n");
    printf("standard  |Len :[%d, %i]\n", len, len);
    printf("custom    |Len2:[%d, %i]\n", l2, l2);

    len = printf("standard  |testing 'c': %c char 1024: %c\n", 'c', 1024);
    l2 = _printf("custom    |testing 'c': %c char 1024: %c\n", 'c', 1024);
    printf("standard  |Len :[%d, %i]\n", len, len);
    printf("custom    |Len2:[%d, %i]\n", l2, l2);

    len = printf("standard  |testing: 'string': %s NULL: %s\n", "string", NULL);
    l2 = _printf("custom    |testing: 'string': %s NULL: %s\n", "string", NULL);
    printf("standard  |Len :[%d, %i]\n", len, len);
    printf("custom    |Len2:[%d, %i]\n", l2, l2);

    len = printf("standard  |testing: %% & unknown directive: %y\n");
    l2 = _printf("custom    |testing: %% & unknown directive: %y\n");
    printf("standard  |Len :[%d, %i]\n", len, len);
    printf("custom    |Len2:[%d, %i]\n", l2, l2);

    return (0);
// (EXPECTED for test case %y) warning: unknown conversion type character 'y' in format
}
