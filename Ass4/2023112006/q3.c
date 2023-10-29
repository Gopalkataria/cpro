#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Color
{
    int index;
    struct Color *next;
} Color;

typedef struct Color *ColorList;

void appendColor(ColorList *C, int index)
{
    ColorList newcolor = (ColorList)malloc(sizeof(Color));
    newcolor->index = index;
    if (*C == NULL)
    {
        *C = newcolor;
    }
    else
    {
        ColorList temp = *C;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newcolor;
    }
}

ColorList removeDuplicates(ColorList C)
{

    if (C == NULL)
    {
        return C;
    }
    ColorList temp = (ColorList)malloc(sizeof(Color));
    temp->index = C->index;
    temp->next = C->next;
    if (temp->next == NULL)
    {
        return temp;
    }
    if (temp->index == temp->next->index)
    {
        temp->next = removeDuplicates(temp->next->next);
    }
    else
    {
        temp->next = removeDuplicates(temp->next);
    }
    return temp;
}

void printColorList(ColorList C)
{
    if (C != NULL)
    {
        printf("%d", C->index);
        C = C->next;
    }

    while (C != NULL)
    {
        printf(" -> %d", C->index);
        C = C->next;
    }
}

int main()
{
    int n, temp;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);
    if (n > 0 )
    {
    printf("Enter the colors: ");
    }
    ColorList colors = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &temp);
        appendColor(&colors, temp);
    }
    ColorList colorsUnique = removeDuplicates(colors);
    printf("\nModified Linked List: ");
    printColorList(colorsUnique);
        
    

    return 0;
}