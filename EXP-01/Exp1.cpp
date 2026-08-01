#include <stdio.h>
#include <string.h>

#define MAX 20

int main()
{
    // Transition table
    // States: 0(Start), 1, 2(Final), 3(Dead)
    // Input: a = column 0, b = column 1
    int trans_table[4][2] = {
        {1, 3},
        {1, 2},
        {1, 2},
        {3, 3}
    };

    int present_state = 0;
    int next_state = 0;
    int final_state = 2;
    int invalid = 0;
    int i;

    char input_string[MAX];

    printf("Enter a string: ");
    scanf("%s", input_string);

    int len = strlen(input_string);

    for(i = 0; i < len; i++)
    {
        if(input_string[i] == 'a')
            next_state = trans_table[present_state][0];
        else if(input_string[i] == 'b')
            next_state = trans_table[present_state][1];
        else
        {
            invalid = 1;
            break;
        }

        present_state = next_state;
    }

    if(invalid)
    {
        printf("Invalid input\n");
    }
    else if(present_state == final_state)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Not Accepted\n");
    }

    return 0;
}
