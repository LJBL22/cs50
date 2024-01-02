#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Make black pixels turn red
            // if black
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                // change rgb color
                image[i][j].rgbtRed = 0x3a;
                image[i][j].rgbtGreen = 0xbc;
                image[i][j].rgbtBlue = 0xaa;
            }
        }
    }
}
