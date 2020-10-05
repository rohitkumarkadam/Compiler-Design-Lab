// C implementation of recursive descent parser program 2
// G = ({S, L}, {(, ), a, ,}, {S → (L) | a ; L→ L, S | S}, S)

//After eliminating left recursion we get
// S -> (L) | a
// L-> SL'
// L'->,SL'|^

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int S(), L(), Ldash();
char *ip;
char string[50];
int main()
{
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");
    if (S() && *ip == '\0')
    {
        printf("\n--------------------------------\n");
        printf("\n String is successfully parsed\n");
    }
    else
    {
        printf("\n--------------------------------\n");
        printf("\n Error in parsing string!\n");
    }
}
int S()
{
    if (*ip == '(')
    {
        printf("%s\tS->(L)\n", ip);
        ip++;
        if (L())
        {
            if (*ip == ')')
            {
                ip++;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if (*ip == 'a')
    {
        ip++;
        printf("%s\tS->a\n", ip);
        return 1;
    }
    else
    {
        return 0;
    }
}

int L()
{
    if (S())
    {
        if (Ldash())
        {
            printf("%s\tL-> SL'\n", ip);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int Ldash()
{
    if (*ip == ',')
    {
        ip++;
        if (S())
        {
            if (Ldash())
            {
                printf("%s\tL'->,SL'\n", ip);

                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("%s\tL'->^\n", ip);
        return 1;
    }
}
