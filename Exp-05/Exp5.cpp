#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, flag = 1, flag1 = 1;
    int l, a, b;

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

    // Check palindrome
    a = 0;
    b = l - 1;

    while(a < b)
    {
        if(s[a] != s[b])
        {
            flag1 = 0;
            break;
        }
        a++;
        b--;
    }

    if(flag1)
    {
        printf("The string is a palindrome\n");
        printf("String is Accepted\n");
    }
    else
    {
        printf("The string is not a palindrome\n");
        printf("String is Not Accepted\n");
    }

    return 0;
}
