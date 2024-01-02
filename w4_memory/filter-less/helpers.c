#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 1. name variables 將三個現值存進 RGB 變數
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            // 2. 利用三個數值相加除以三、取最大整數
            int AVERAGE = round((R + G + B) / 3.0);

            // 3. 賦值 rgb channels
            image[i][j].rgbtRed = AVERAGE;
            image[i][j].rgbtGreen = AVERAGE;
            image[i][j].rgbtBlue = AVERAGE;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 1. to name variables
            int R = image[i][j].rgbtRed;
            int G = image[i][j].rgbtGreen;
            int B = image[i][j].rgbtBlue;

            // 2. store algorithm result to new variables sepiaX (a temp place)
            int sepiaR = round(.393 * R + .769 * G + .189 * B);
            int sepiaG = round(.349 * R + .686 * G + .168 * B);
            int sepiaB = round(.272 * R + .534 * G + .131 * B);

            // 3. assign value with ternary operator
            image[i][j].rgbtRed = (sepiaR > 255) ? 255 : sepiaR;
            image[i][j].rgbtGreen = (sepiaG > 255) ? 255 : sepiaG;
            image[i][j].rgbtBlue = (sepiaB > 255) ? 255 : sepiaB;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // deal with rows
    for (int i = 0; i < height; i++)
    {
        // deal with pixels at the same row
        for (int j = 0; j < width / 2; j++) // divided 2, otherwise swap again = didn't change
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// mirror image ...LOL
// void mirror(int height, int width, RGBTRIPLE image[height][width])
// {
//     // deal with rows
//     for (int i = 0; i < height; i++ )
//     {
//         // deal with pixels at same row
//         int middle = 0;
//         if (width % 2 == 0) // 雙數
//         {
//             middle = (width/2) - 1;
//         }
//         else // 單數
//         {
//             middle = width / 2;
//         }

//         for (int j = 0; j <= middle; j++)
//         {
//             image[i][j] = image[i][width-j];
//         }
//     }
//     return;
// }

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image to change
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Check if each surrounding pixel exists.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialise values
            float sum_red = 0;
            float sum_blue = 0;
            float sum_green = 0;
            int count = 0;

            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++) // k 值限定在 -1 0 1
            {
                for (int l = -1; l < 2; l++) // 同上
                {
                    if (i + k < 0 | i + k >= height) // i + k 會是 -1 0 1 ，檢查有沒有超過範圍
                    {
                        continue; // 若符合=超過，則直接跳出迴圈 -> for loop of l -> 結束後再跳 k
                    }

                    if (j + l < 0 | j + l >= width) // 概念同上
                    {
                        continue;
                    }
                    // 通過則將值加入各色總計
                    sum_red += copy[i + k][j + l].rgbtRed;
                    sum_blue += copy[i + k][j + l].rgbtBlue;
                    sum_green += copy[i + k][j + l].rgbtGreen;
                    count++;
                }
            }
            // Get average -> 求得一格 image[0][0] 接著跳出迴圈、j = 1 => image[0][1]
            image[i][j].rgbtRed = round(sum_red / count);
            image[i][j].rgbtGreen = round(sum_green / count);
            image[i][j].rgbtBlue = round(sum_blue / count);
        }
    }
}
