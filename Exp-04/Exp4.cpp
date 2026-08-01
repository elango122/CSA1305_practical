#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, flag = 1;
    int l;

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
    }
    else
    {
        if(s[0] == '0' && s[l - 1] == '1')
        {
            printf("String is Accepted\n");
        }
        else
        {
            printf("String is Not Accepted\n");
        }
    }

    return 0;
}
