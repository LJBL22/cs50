#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David" };
    string numbers[] = {"0910-123-456", "0918-456-878" };

    string name = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i],name) == 0)
        {
            printf("Found the number is %s\n", numbers[i]);
            return 0;
        }
    }
        printf("Not found\n");
        return 1;
}