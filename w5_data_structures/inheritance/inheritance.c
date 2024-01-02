// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));
    // time(0) 會回傳字 1970/1/1 始至當前當下的秒數
    // srand 基於種子值回傳『相對應、固定的』隨機序列

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0); // 這裡先傳入 0 ，函式設計再往上加

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *np = malloc(sizeof(person));
    if (np == NULL)
    {
        return NULL; // err: should return a value
    }
    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // // TODO: Set parent pointers for current person
        np -> parents[0] = parent0; //即使是指針也是可以利用索引來訪問
        np -> parents[1] = parent1;

        // // ⭐ TODO: Randomly assign current person's alleles based on the alleles of their parents
        for (int i = 0, r = rand() % 2; i < 2; i++)
        {
            np -> alleles[i] = np -> parents[i] -> alleles[r];
        }
    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        np -> parents[0] = NULL;
        np -> parents[1] = NULL;
        // TODO: Randomly assign alleles
        np -> alleles[0] = random_allele();
        np -> alleles[1] = random_allele();
    }

    // ⭐ TODO: Return newly created person
    return np;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }

    // TODO: Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // TODO: Free child
    free(p);

    // // TODO: Free parents recursively
    // person *ptr = p;
    // person *parent0 = ptr->parents[0];
    // person *parent1 = ptr->parents[1];

    // // while(parent0 != NULL && parent1 != NULL) // 錯誤示範=>重複判斷 NULL
    // // {
    //     // 繼續往下指，指到為 NULL // 思考有對，但是這件事要用 recursive 而不是 while 來做
    //     // person *parent0 = ptr->parents[0];
    //     // person *parent1 = ptr->parents[1];

    //     // free()
    // free_family(parent0);
    // free_family(parent1);
    // // }

    // // TODO: Free child
    // // free(parent1); //跳 double free error
    // free(parent0);
    // free(ptr);
    // // free(p);

    // chatGPT
    //  while (p != NULL)
    // {
    //     person *temp = p;  // 暫存當前節點
    //     p = p->parents[0]; // 移到左父節點
    //     free(temp);        // 釋放當前節點
    // }
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        // printf("why\n"); //還沒 free
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
// 0~RAND_MAX % 3 只會有 0, 1, 2 三種可能
char random_allele()
{
    int r = rand() % 3;

    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
