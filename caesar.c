#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)         //counting the command line arguments
    {
        bool non_digit_found = false;  //checking for the
        //presence of non digits by iterating over the second string
       
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            int non_digit_flag = isdigit(argv[1][i]);
           
            if (non_digit_flag == 0)
            {
                non_digit_found = true;
               
                break;
            }
           
        }
        
        if (non_digit_found == false) //if the string contains digits only convert
//them to integer
        {
            int key = atoi(argv[1]);
            
            string plain_text = get_string("plaintext: ");
            
            printf("ciphertext: ");
            
            for (int i = 0, n = strlen(plain_text) ; i < n ; i++)
            {
                if ((plain_text[i] >= 'a' && plain_text[i] <= 'z') || (plain_text[i] >= 'A' 
                        && plain_text[i] <= 'Z'))  //checking for letters and deciphering them according to the key
                {
                    if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
                    {
                        //this part is for wrapping Z to A
                        char cipher_char = ((plain_text[i] - 'A' + key) % 26) + 'A';
                          
                        printf("%c", cipher_char);
                    }
                    // here we wrap z to a
                    else if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
                    {
                        char cipher_char = ((plain_text[i] - 'a' + key) % 26) + 'a';
                          
                        printf("%c", cipher_char);
                    }
                }
                
                else
                {
                    printf("%c", plain_text[i]); //if not alphabet (e.g:.,-!+=$%) just print it as it is 
                }
                    
            }
            
            printf("\n");
        
        }
        
        else 
        {
            printf("Usage: ./caesar key\n");
        }
    }
    
    else
    {
        printf("Usage: ./caesar key\n");   //displaying the right
        //usage for the user
    }
}
