/* this is a program to cipher an incoming text using a certain key
 * that the user passes to the main function
 *
 *  WELCOME TO VIGENERE 1.0    */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int shift(char c);

int main(int argc, string argv[])
{
    if (argc == 2)         //counting the command line arguments
    {
        bool non_alpha_found = false;  //checking for the
        //presence of non alphabets by iterating over the second string

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            int non_alpha_flag = isalpha(argv[1][i]);

            if (non_alpha_flag == 0)
            {
                non_alpha_found = true;

                break;
            }

        }

        if (non_alpha_found == false) //if the string contains alphabets only, convert
//each alphabet to it's corresponding value in the cipher
        {
            int keyword_length = strlen(argv[1]);

            int last_keyword_index = keyword_length - 1;

            string plain_text = get_string("plaintext: ");

            int plain_text_length = strlen(plain_text);

            printf("ciphertext: ");

            int keyword_index;

            bool not_character;
            
            int key_counter = 0;

            keyword_index = 0;

            for (int i = 0, n = strlen(plain_text) ; i < n ; i++)  //iterating over the plaintext
            {
                if ((plain_text[i] >= 'a' && plain_text[i] <= 'z') || (plain_text[i] >= 'A'
                        && plain_text[i] <= 'Z')) //checking for alphabets only
                {
                    not_character = false;
                     
                    if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
                    {
                        if (key_counter > last_keyword_index) //if the counter is bigger than the last index of the keyword, reset the index and counter.
                        {
                            keyword_index = 0;

                            key_counter = 0;
                        }

                        char cipher_char = ((plain_text[i] - 'A' + shift(argv[1][keyword_index])) % 26) + 'A';

                        printf("%c", cipher_char);
                    }

                    else
                    {
                        if (key_counter > last_keyword_index)
                        {
                            keyword_index = 0;
                              
                            key_counter = 0;
                        }

                        char cipher_char = ((plain_text[i] - 'a' + shift(argv[1][keyword_index])) % 26) + 'a';

                        printf("%c", cipher_char);
                    }

                }

                else
                {
                    printf("%c", plain_text[i]);

                    not_character = true;
                }

                if (not_character == false)
                {
                    keyword_index++;
                     
                    key_counter++;
                }
            }

            printf("\n");

        }

        else
        {
            printf("Usage: ./vigenere keyword\n");
        }

    }

    else
    {
        printf("Usage: ./vigenere keyword\n");   //displaying the right
        //usage for the user
        return 1;
    }
}

int shift(char 
          c)  //this function returns the integer shift of letters to encipher the plain text , so if it is given A or a the corresponding shift is zero, B or b corresponds to 1 and so on.
{
    if (c >= 'a' && c <= 'z')
    {
        c = c - 97;
    }

    else if (c >= 'A' && c <= 'Z')
    {
        c = c - 65;
    }

    else
    {
        return -1;
    }

    int shift_value = (int)c;

    return shift_value;
}


