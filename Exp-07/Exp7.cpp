#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, l;
    int flag = 1, flag1 = 1, flag2 = 1;

    printf("Enter a string to check: ");
    scanf("%s", s);

    l = strlen(s);

    // Check whether the string contains only 0 and 1
    for(i = 0; i < l; i++)
    {
        if(s[i] != '0' && s[i] != '1')
        {
            flag = 0;
            break;
        }
    }

    if(flag == 0)
    {
        printf("String is Not Valid\n");
        return 0;
    }

    // Length must be even
    if(l % 2 != 0)
    {
        printf("The string does not satisfy the condition 0^n1^n\n");
        printf("String Not Accepted\n");
        return 0;
    }

    // First half should contain only 0's
    for(i = 0; i < l / 2; i++)
    {
        if(s[i] != '0')
        {
            flag1 = 0;
            break;
        }
    }

    // Second half should contain only 1's
    for(i = l / 2; i < l; i++)
    {
        if(s[i] != '1')
        {
            flag2 = 0;
            break;
        }
    }

    if(flag1 == 1 && flag2 == 1)
    {
        printf("The string satisfies the condition 0^n1^n\n");
        printf("String Accepted\n");
    }
    else
    {
        printf("The string does not satisfy the condition 0^n1^n\n");
        printf("String Not Accepted\n");
    }

    return 0;
}
