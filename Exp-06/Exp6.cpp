#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, l;
    int flag = 1, flag1 = 1;
    int count1 = 0, count2 = 0;

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

    i = 0;

    // Count leading 0's
    while(i < l && s[i] == '0')
    {
        count1++;
        i++;
    }

    // Skip middle 1's
    while(i < l && s[i] == '1')
    {
        i++;
    }

    // Count trailing 0's
    while(i < l)
    {
        if(s[i] == '0')
        {
            count2++;
        }
        else
        {
            flag1 = 0;
            break;
        }
        i++;
    }

    if(flag1 && count1 == count2)
    {
        printf("The string satisfies the condition 0^n1^m0^n\n");
        printf("String Accepted\n");
    }
    else
    {
        printf("The string does not satisfy the condition 0^n1^m0^n\n");
        printf("String Not Accepted\n");
    }

    return 0;
}
