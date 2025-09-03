// Prints a row of 3 question marks with a loop

#include <stdio.h>

void print_row(int width);

int main(void)
{
    const int n = 3;
    
    // Print n rows
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
    printf("\n");


}

void print_row(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("#");
    }
    printf("\n");
}
