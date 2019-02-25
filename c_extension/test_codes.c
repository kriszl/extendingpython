#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);
void prime_fact(int n);
void greatest_comm(int n, int x);
void merged_prime(int n);

int main(void)
{
    /*
    This file is just here for testing purpose and it is not needed for the extension module.
    However I'd suggest you to test your C based functions in a different file, because it
    makes it much easier to debug your code.
    The other functions need to be run inside of the main function for testing purpose.
    */
    int input;

    printf("input: ");
    scanf("%d", &input);

    // printf("%s", x ? "true" : "false");
    //printf("res: %d\n", is_prime(input));
    //printf("%s\n", is_prime(input) ? "true" : "false");
    //prime_fact(input);
    greatest_comm(12, 6);
    //merged_prime(input);
    is_prime(input);
    printf("regular is prime: %d\n", is_prime(input));
    merged_prime(input);

    return 0;
}

bool is_prime(int n)
{
    /*
    either returns bool or returns an integer represeting the bool values
    */
    for (int divisor = 2; divisor * divisor <= n; divisor++)
        if (n % divisor == 0)
            return false;
        else
            return true;
}

void greatest_comm(int n, int x)
{
    int remainder;

    while (x != 0) {
        remainder = n % x;
        n = x;
        x = remainder;
    }

    printf("%d\n", n);
}

void prime_fact(int n)
{
    while (n % 2 == 0) {
        printf("%d ", 2);
        n /= 2;
    }

    for (int divisor = 3; divisor * divisor <= n; divisor++)
        while (n % divisor == 0) {
            printf("%d ", divisor);
            n /= divisor;
        }

    if (n > 2)
        printf("%d ", n);

    printf("\n");
}

void merged_prime(int n)
{
    bool flag = true;

    for (int divisor = 2; divisor * divisor <= n; divisor++)
        if (n % divisor == 0)
            flag = false;
    printf("%s\n", flag ? "true" : "false");
}
