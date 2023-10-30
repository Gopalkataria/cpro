#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// -----------------------------
//    Color List Code
// -----------------------------

// Define a structure for Color and an alias ColorList for pointer to Color
typedef struct Color
{
    int index;
    struct Color *next; // Pointer to the next color
} Color;

typedef struct Color *ColorList;

// Function to append a new color to the end of the linked list
void appendColor(ColorList *C, int index)
{
    // Allocate memory for a new color
    ColorList newcolor = (ColorList)malloc(sizeof(Color));
    newcolor->index = index; // Set the color index

    if (*C == NULL)
    {
        *C = newcolor; // If the list is empty, make the new color the head
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

// Function to remove duplicate colors from the linked list
ColorList removeDuplicates(ColorList C)
{
    if (C == NULL)
    {
        return C; // If the list is empty, no duplicates to remove
    }

    ColorList temp = (ColorList)malloc(sizeof(Color));
    temp->index = C->index;
    temp->next = C->next;

    if (temp->next == NULL)
    {
        return temp; // If only one color in the list, return it
    }

    if (temp->index == temp->next->index)
    {
    again:
        temp->next = removeDuplicates(temp->next->next); // Remove duplicate, keep the next distinct color
        if (temp->next != NULL && temp->index == temp->next->index)
            goto again;
    }
    else
    {
        temp->next = removeDuplicates(temp->next);
    }

    return temp;
}

// Function to print the linked list of colors
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

    if (n > 0)
    {
        printf("Enter the colors: ");
    }

    ColorList colors = NULL; // Initialize an empty list

    // Loop to read and append colors to the list
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &temp);
        appendColor(&colors, temp);
    }

    ColorList colorsUnique = removeDuplicates(colors); // Remove duplicate colors

    printf("Modified Linked List: ");
    printColorList(colorsUnique); // Print the modified linked list
    printf("\n");
    return 0;
}
