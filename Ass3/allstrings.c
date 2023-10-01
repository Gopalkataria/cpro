#include <stdio.h>
#include <string.h>


#define ps(x) printf("%s -\n", x);
#define pc(x) printf("%c -\n", x);
#define pi(x) printf("%i -\n", x);

char PERMS[40320][8];
int n = 0;

void savetoPERMS(char *str)
{
    strcpy(PERMS[n], str);
    n++;
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

int main()
{
    for (int i = 0; i < 40320; i++)
        strcpy("", PERMS[i]);

    char inp[8];
    scanf("%s", inp);
    perms(inp, strlen(inp));
    printf("%d\n", n);

    for (int i = 0; i < n; i++)
        printf("%s\n", PERMS[i]);
    return 0;
}

void printvariation( char * previnp , char * inpt , int l ) {
    char inps [l] ; 
    char prev[l] ;
    strcpy(inps, inpt);
    strcpy(prev, previnp);
    // printf("%d" , l ) ;  
    if ( l == 1) {
        printf("%s  ", prev);
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
                strcat(prev, &inps[i] );
                // printf("%s -o\n" , prev ); 
                char new[10] ;

                withoutn(inps, new, i, l) ; 
                // printf("%s \n", new) ; 
                printvariation( prev , new , l-1) ; 
                
            }            
        }
        // printf("DEBUG %s" , uniq) ; 
        
    }

}

