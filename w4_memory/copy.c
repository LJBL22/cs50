#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // ORIGINAL (assign to the same memory address)
    // string s= get_string("s: ");
    // string t = s;
    // char *s = get_string("s: ");
    // char *t = s;
    // if (strlen(t) > 0)
    // {
    //     t[0] = toupper(t[0]);
    // }
    // printf("s: %s\n", s);
    // printf("t: %s\n", t);

    // MALLOC
    char *s = get_string("s: ");
    if (s == NULL) //跟 get_string 的特性有關，多加這個
    {
        return 1;
    }
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // for (int i = 0, n = strlen(s) + 1; i < n; i++)
    // // 關於命名n：避免在 for loop 中重複呼叫 strlen ，他就只是一個單純不會變得 Int
    // // 關於 +1：這裡沒有感覺，但如果是大型的專案，不寫 + 1 個位元給 NUL 的話，可能會印出中間任何東西直到找到下個 NUL 用以結尾
    // {
    //     t[i] = s[i];
    // }
    strcpy(t, s); //取代上方

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);

    return 0;
}