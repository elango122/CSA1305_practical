#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, l;
    int flag = 1, found = 0;

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

    // Check for substring "101"
    for(i = 0; i < l - 2; i++)
    {
        if(s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1')
        {
            found = 1;
            break;
        }
    }

    if(found)
    {
        printf("Substring 101 exists.\n");
        printf("String Accepted\n");
    }
    else
    {
        printf("Substring 101 does not exist.\n");
        printf("String Not Accepted\n");
    }

    return 0;
}
