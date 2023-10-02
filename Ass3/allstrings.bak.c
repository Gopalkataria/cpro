#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

#define ps(x) printf("%s -\n", x);
#define pc(x) printf("%c -\n", x);
#define pi(x) printf("%i -\n", x);

char PERMS[40320][8];
int N = 0;

void pushtoWORDS(char *str)
{
    strcpy(PERMS[N], str);
    N++;
}

// #define ps(x) printf(" %s ", x)
void withoutn(char *inst, char *new, int remove, int len)
{
    int i;
    for (i = 0; i < remove; i++)
    {
        new[i] = inst[i];
    }
    for (i = (remove + 1); i < len; i++)
    {
        new[i - 1] = inst[i];
    }
}
void withoutc(char *inst, char *new, char remove , int len)
{
    int i;
    for (i = 0; i < len ; i++)
    {   
        if (inst[i] == remove)
        {
            break;
        }
        new[i] = inst[i] ;
        
    }
    i++ ; 
    for (; i < len; i++)
    {
        new[i - 1] = inst[i];
    }
}

void printvariation( char * previnp , char * inpt , int l ) {
    char inps [l] ; 
    char prev[l] ;
    strcpy(inps, inpt);
    strcpy(prev, previnp);
    // printf("%d" , l ) ;  
    if ( l == 1) {
        printf("%s", prev);
        printf("%c --\n", *inps);
    } else {
        char uniq[10] ;
        int count = 0 , flag = 1;  
        for (int i = 0; i < l; i++)
        {
            flag = 1 ; 
            for (int j = 0; j < count; j++)
            {
               if (inps[i] == uniq[j])
               {
                flag = 0 ; 
               }
               
            }
            if ( flag ) {
                uniq[count] = inps[i] ; 
                count++ ; 
                // strcat(prev, &inps[i] );
                // // printf("%s -o\n" , prev ); 
                // char new[10] ;

                // withoutn(inps, new, i, l) ; 
                // // printf("%s \n", new) ; 
                // printvariation( prev , new , l-1) ; 
                
            }            
        }
        qsort(uniq,count,sizeof(int),cmp ) ; 
        for (int i = 0; i < count; i++)
        {   
            char newprev[10] ; 
            strcpy(newprev , prev) ; 
            strcat(newprev, &uniq[i]); 
            char new[10];
            withoutc( inps , new , uniq[i] , l-1) ; 
            printvariation(newprev, new, l-1);
            
        }
        

        // printf("DEBUG %s" , uniq) ; 
        
    }

}

int main()
{
    // for (int i = 0; i < 40320; i++)
    //     strcpy("", PERMS[i]);

    char inp[8];
    scanf("%s", inp);
    char pre[] = "";
    
    printvariation(pre, inp, strlen(inp));
    // printf("%d\n", N);

    // for (int i = 0; i < N; i++)
    //     printf("%s\n", PERMS[i]);
    return 0;
}
