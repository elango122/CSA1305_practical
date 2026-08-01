#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, m;
    int next_state[20], n, mat[10][10][10];
    int flag, p;
    int num_states, final_state[5], num_symbols, num_final;
    int present_state[20], prev_trans, new_trans;
    int symbol[5], inp, inp1;
    char input[20];

    printf("How many states in the NFA: ");
    scanf("%d", &num_states);

    printf("How many symbols in the input alphabet: ");
    scanf("%d", &num_symbols);

    for(i = 0; i < num_symbols; i++)
    {
        printf("Enter input symbol %d (0 or 1): ", i + 1);
        scanf("%d", &symbol[i]);
    }

    printf("How many final states: ");
    scanf("%d", &num_final);

    for(i = 0; i < num_final; i++)
    {
        printf("Enter final state %d: ", i + 1);
        scanf("%d", &final_state[i]);
    }

    // Initialize transition table
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            for(k = 0; k < 10; k++)
                mat[i][j][k] = -1;

    // Read transitions
    for(i = 0; i < num_states; i++)
    {
        for(j = 0; j < num_symbols; j++)
        {
            printf("\nHow many transitions from state %d for input %d: ",
                   i, symbol[j]);
            scanf("%d", &n);

            for(k = 0; k < n; k++)
            {
                printf("Enter transition %d: ", k + 1);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }

    printf("\nEnter input string: ");
    scanf("%s", input);

    present_state[0] = 0;
    prev_trans = 1;

    l = strlen(input);

    for(i = 0; i < l; i++)
    {
        if(input[i] == '0')
            inp1 = 0;
        else if(input[i] == '1')
            inp1 = 1;
        else
        {
            printf("Invalid Input\n");
            return 0;
        }

        for(m = 0; m < num_symbols; m++)
        {
            if(inp1 == symbol[m])
            {
                inp = m;
                break;
            }
        }

        new_trans = 0;

        for(j = 0; j < prev_trans; j++)
        {
            k = 0;
            p = present_state[j];

            while(mat[p][inp][k] != -1)
            {
                next_state[new_trans++] = mat[p][inp][k];
                k++;
            }
        }

        for(j = 0; j < new_trans; j++)
            present_state[j] = next_state[j];

        prev_trans = new_trans;
    }

    flag = 0;

    for(i = 0; i < prev_trans; i++)
    {
        for(j = 0; j < num_final; j++)
        {
            if(present_state[i] == final_state[j])
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag)
        printf("\nAccepted\n");
    else
        printf("\nNot Accepted\n");

    return 0;
}
