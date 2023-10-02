#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char WORDS[40321][9];
int N = 0;

void pushtoWORDS(char *str) // push all words to a global array
{
    strcpy(WORDS[N], str);
    N++;
}

int cmp_char(const void *a, const void *b) // for qsort 
{
    return (*(char *)a - *(char *)b);
}

void sort_char_arr(char *arr, int size) // for sorting the unique elems
{
    qsort(arr, size, sizeof(char), cmp_char);
}

int unique_chars(char *destination, char *source) // find unique chars of a string
{
    int len = strlen(source), count = 0, isuniq;
    char uniq[9];
    for (int i = 0; i < len; i++)
    {
        isuniq = 1;                       // assume is unique
        for (int j = i + 1; j < len; j++) // compare with others
        {
            if (source[i] == source[j])
            {
                isuniq = 0;
            }
        }
        if (isuniq)
        {
            uniq[count] = source[i];
            count++;
        }
    }
    uniq[count] = '\0'; // terminating the string
    strcpy(destination, uniq);

    return count;
}

void withoutchar(char *destination, char *source, char unwanted)
{
    int len = strlen(source), i = 0, islooking = 1 ;
    char new[9] ; 
    for (i = 0; i < len+1; i++)
    {
        // printf("tf");
        if ((source[i] == unwanted) && islooking)
        {
            islooking = 0;
            continue;
        }
        else
        {
            // printf("t");
            if (islooking)
                new[i] = source[i];
            else
                new[i - 1] = source[i];
            // i++ ;
        }
        // printf("%c " , source[i]) ;
    }
    strcpy(destination , new ) ; 
}

void variations(char *prev, char *inp)
{
        // printf("%d ", strlen(inp)) ;
        // printf("\n %s %s \n", prev, inp);

        if (strlen(inp) == 1)
        {
            char output[9] ; 
            strcpy(output , prev) ;
            strcat(output, inp);
            pushtoWORDS(output);
            // printf("%s%s\n", prev, inp);
        } else {
        
    

        char unique[9];
        int unique_count = unique_chars(unique, inp);
        sort_char_arr(unique, unique_count);
        for (int i = 0; i < unique_count; i++)
        {
            char newprev[9];
            strcpy(newprev, prev);
            strncat(newprev, &unique[i],1);
            char newinp[9];
            withoutchar(newinp, inp, unique[i]);
            // printf("\n %s %s \n" , newprev, newinp);
            variations(newprev, newinp);
        }
        }
}

int main()
{
    char input[9] , emp[] = "";
    scanf("%s", input) ; 
    variations(emp , input) ; 
    printf("%d\n", N) ; 
    for (int x = 0; x < N; x++)
    {
        printf("%s\n", WORDS[x]);
    }
    
    return 0;
}