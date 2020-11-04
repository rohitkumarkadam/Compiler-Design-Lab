/*  
Recursive Descent Parser for following grammer
S-> aBa
B->bB|epsilon
Rohitkumar Shankar Kadam
AP18110010253
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = 0, i = 0;
char stack[20], in[20];

void push(char c)
{
    if (top >= 20)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[top++] = c;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack Underflow");
    }
    else
    {
        top--;
    }
}

void error()
{
    printf("Syntax error string is invalid!!!");
    exit(0);
}
int main()
{
    int n;
    printf("Given grammer is \n\n");
    printf("S-> aBa\n");
    printf("B->bB|epsilon\n");
    printf("Enter string to be parsed: \n");
    scanf("%s", in);
    n = strlen(in);
    in[n] = '$';
    in[n + 1] = '\0';
    push('$');
    push('S');
    while (in[i] != '\0')
    {
        if (in[i] == '$' && stack[top - 1] == '$')
        {
            printf("\n\nString parsed successfully\n");
            return 1;
        }
        else
        {
            if (in[i] == stack[top - 1])
            {
                printf("\n Match of %c", in[i]);
                i++;
                pop();
            }
            else
            {
                if (stack[top - 1] == 'S' && in[i] == 'a')
                {
                    printf("\n S->aBa");
                    pop();
                    push('a');
                    push('B');
                    push('a');
                }
                else
                {
                    if (stack[top - 1] == 'B' && in[i] == 'b')
                    {
                        printf("\n B->bB");
                        pop();
                        push('B');
                        push('b');
                    }
                    else
                    {
                        if (stack[top - 1] == 'B' && in[i] == 'a')
                        {
                            printf("\nB->epsilon");
                            pop();
                        }
                        else
                        {
                            error();
                        }
                    }
                }
            }
        }
    }
}
