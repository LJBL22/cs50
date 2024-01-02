#include <cs50.h>
#include <stdio.h>

int get_size(void); //手動 hoisting
void print_grid(int size);

int main(void)
{
    int n = get_size();
    print_grid(n);
}

int get_size(void) // 這裡不用輸入
{
    int n;
    do
    {
        n = get_int("Size: "); //而是這個 function 會負責取得輸入的資料
    }
    while (n < 1);
    return n;
}

void print_grid(int size) //代表不會輸出、需要輸入一個 int 變數命名為 size
{
    for(int i = 0; i < size; i++)
        {
        for(int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
        }
}