#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

FILE *readptr;
FILE *img;

int main(int argc, char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./recover image\n");
        return 1;
    }

    //open the forensic image file
    readptr = fopen(argv[1], "r");

    //file cannot be opened
    if (readptr == NULL)
    {
        fprintf(stderr, "the forensic image cannot be opened for reading\n");
        return 2;
    }

    bool jpeg_found = false;

    int image_number = 0;

    char *title;

    //repeat until end of file is reached
    while (1)
    {
        unsigned char *buffer = malloc(512);

        fread(buffer, 1, 512, readptr);

        if (feof(readptr))
        {
            break;
        }

        //signature of the start of image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //indicate that this is the first block of the first image
            if (jpeg_found == false)
            {
                jpeg_found = true;

                title = malloc(8);

                sprintf(title, "%03i.jpg", image_number);

                img = fopen(title, "w");

                fwrite(buffer, 1, 512, img);

                free(buffer);
            }
            //indicates the first block of another image
            else
            {
                free(title);

                image_number ++;

                fclose(img);

                title = malloc(8);

                sprintf(title, "%03i.jpg", image_number);

                img = fopen(title, "w");

                fwrite(buffer, 1, 512, img);

                free(buffer);
            }
        }
        //indicates other blocks in the memory that are not the start of any jpeg
        else
        {
            //indicates the rest of the blocks of the jpeg
            if (jpeg_found == true)
            {
                fwrite(buffer, 1, 512, img);

                free(buffer);
            }
            //the blocks preceding the first jpeg so they are skipped
            else
            {
                free(buffer);

                continue;
            }
        }
    }

    free(title);

    fclose(img);

    fclose(readptr);

    return 0;
}
