#include <stdio.h>
#include <cs50.h>

void build_pyramid(int height);

int main(void)
{
    // Default value outside of acceptable range
    int user_input = -1;

    // Don't let the user pass a value outside of 1-8 inclusive
    while (user_input <= 0 || user_input > 8)
    {
        user_input = get_int("Input an integer: ");
    }

    // If the user passes an acceptable value, build a pyramid
    build_pyramid(user_input);
}

void build_pyramid(int height)
{
    // Creates a new row, up to height
    for (int i = 0; i < height; i++)
    {
        // Print spaces up to height-1, builds empty space to the left
        for (int x = height; x-1 > i; x--)
        {
           printf(" ");
        }

        // Print the same number of blocks as the current height
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        // Leave two spaces
        printf("  ");

        // Print the same number of blocks as the current height
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}
