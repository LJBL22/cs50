#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *input = argv[1];
    FILE *input_file = fopen(input, "r");
    if (input_file == NULL)
    {
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input_file); // 從 "input_file" 讀取 "1" 個 “WAVHEADER” 的數量，存到 “header 門牌位置“

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Not a wav file\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    char *output = argv[2];
    FILE *output_file = fopen(output, "w");
    if (output_file == NULL)
    {
        return 1;
    }

    // Write header to file
    // audio data 之前的 44 bytes 都是 Header (meta data)
    // 又因為兩者架構相同 因此可以直接比照、寫入跟原先相同的 header
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output_file);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    if (fseek(input_file, block_size, SEEK_END))
    {
        return 1;
    }
    // 白話文是：將 ptr 放至末端、並返回一個字節，成功後即繼續往下執行程式碼
    // fseek 特性，成功會返回 0 也就是 false，條件為假不執行。
    // 失敗返回非零值，也就是 true ，因此會繼續 if statement 內的執行，也就是失敗的 return 1。
    // 你當機了嗎？ if (true) 才會執行對吧？所以回到第二行

    // declare an array to store each block
    BYTE buffer[block_size]; // ⭐ BYTE
    // iterate through the input file audio data
    // 執行到這裡，指針在末端，檢測 指針-b_s 會大於()，即執行。     // avoid header
    // 執行到一次讀取寫入之後，再重複迴圈檢測直到 false
    while (ftell(input_file) - block_size > sizeof(header)) // ftell(input_file) 是一個整數
    { // 每次都需要判斷，inptr 指針現在的位置--能不能正向往前移動 2 節，可以的話才執行讀取寫入
        // | header | bs1 | bs2 | bs3 | xxx
        //                                ＾ ptr 在這裡 第一次迴圈不成立，因此會進入第二次迴圈，開始取 bs3 寫入
        if (fseek(input_file, -2 * block_size, SEEK_CUR)) // 成功返回 0 ，條件為假不執行，故繼續往下
        {
            return 1;
        }
        fread(&buffer, sizeof(block_size), 1, input_file);
        fwrite(&buffer, sizeof(block_size), 1, output_file);
    }
    // 總結： while 負責從末端開始倒退
    // 條件句會判別讀取對象
    // fread 會取當下那一節
    // fwrite 接著讓 output 順向寫入

    fclose(output_file);
    fclose(input_file);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1; // true
    }
    return 0; // false
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    // bytes
    // number of channels (*) by bytes per sample
    return header.numChannels * header.bitsPerSample / 8;
}