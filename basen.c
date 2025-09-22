#include <stdio.h>

void to_base_n(unsigned long n, int base);

int main(void)
{
    unsigned long number;
    int base;

    printf("Enter an integer and a base (q to quit):\n");
    while (scanf("%lu"
                 "%d",
                 &number, &base) == 2)
    {
        if (base < 2 || base > 16)
        {
            printf("Error: base %d not supported.\n", base);
        }
        else
        {
            if (base == 8)
            {
                printf("0");
            }
            if (base == 16)
            {
                printf("0x");
            }
            to_base_n(number, base);
        }

        putchar('\n');
        printf("Enter an integer and a base(q to quit):\n");
    }

    printf("Done.\n");
    return 0;
}

void to_base_n(unsigned long n, int base)
{
    char digits[] = "0123456789abcdef";
    int r = n % base;
    if (n >= (unsigned long)base)
    {
        to_base_n(n / base, base);
    }
    putchar(digits[r]);
}