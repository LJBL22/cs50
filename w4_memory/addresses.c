// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int n = 50;
    // int *p = &n;
    // //the address of integer in memory
    // printf("%p\n", &n);//0x7fff85b7e7cc
    // printf("%p\n", p);//print the same

    // string s = "HI!";
    char *s = "HI!";
    printf("%c\n", *s); //char “H”
    printf("%c\n", *(s+1)); //char “I”
    printf("%c\n", *(s+2)); //char “!”
    printf("%c\n", *(s+3)); //char “/0”
    // printf("%c\n", *(s+50000)); //Segmentation fault (core dumped)
    printf("%s\n", s); //string “HI!”
    printf("%s\n", s+1); //string “I!”
    printf("%s\n", s+2); //string “!”

    printf("%p\n", &s); //“HI!” 的起始記憶體位置
    printf("跟下面一樣%p\n", s); //變數 s 的記憶體位置
    printf("%p\n", &s[0]); //等同於第一個c 的門牌位置
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}