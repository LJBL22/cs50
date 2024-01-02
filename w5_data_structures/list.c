#include <stdio.h>
#include <stdlib.h>

// int main(void)
// {
//     int *list = malloc(3 * sizeof(int));
//     if (list == NULL)
//     {
//         return 1;
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         list[i] = i + 1;
//         // printf("%i",list[i]);
//     }

//     int *tmp = malloc(4 * sizeof(int));

//     if (tmp == NULL)
//         {
//             free(list);
//             return 1;
//         }

//     for (int i = 0; i < 3; i++)
//     {
//         tmp[i] = list[i];
//     }

//     tmp[3] = 4;

//     free(list);

//     list = tmp;

//     for(int i = 0; i < 4; i++)
//     {
//         printf("%i\n", list[i]);
//     }

//     free(list);
//     list = NULL;
//     return 0;
// }

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        list[i] = i + 1;
    }

    int *tmp = realloc(list, 4 * sizeof(int)); //realloc

    if (tmp == NULL)
        {
            free(list);
            return 1;
        }

    // // realloc did the copy loop
    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i] = list[i];
    // }

    // tmp[3] = 4; //change place

    // //realloc did the free (or doesn't need to)
    // free(list);

    list = tmp;

    list[3] = 4; //change to here & assign list[3] instead

    for(int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    list = NULL;
    return 0;
}