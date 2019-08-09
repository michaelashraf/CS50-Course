/* this is a program to print adjacent pyramids of blocks like the ones in Nintendo's
 * Super mario,an input is taken from the user to determine the height of the pyramid 
 * and then adjacent pyramids are displayed with the given height
 * if the user doesn't cooperate he/she is repromted to enter the height
 * 
 * *****************   THIS IS MARIO WORLD 1-1  ******************** 
 * 
 * this is a representation of the grid used to implement the algorithm
 * 
 *             1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
 *           1 - - - - - - - # -  - #  -  -  -  -  -  -  - 
 *           2 - - - - - - # # -  - #  #  -  -  -  -  -  -
 *           3 - - - - - # # # -  - #  #  #  -  -  -  -  -
 *           4 - - - - # # # # -  - #  #  #  #  -  -  -  -
 *           5 - - - # # # # # -  - #  #  #  #  #  -  -  -
 *           6 - - # # # # # # -  - #  #  #  #  #  #  -  -
 *           7 - # # # # # # # -  - #  #  #  #  #  #  #  -
 *           8 # # # # # # # # -  - #  #  #  #  #  #  #  #
 *          
 *  ___________________________________________________________________
 * 
 * 
 * */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    
    while (1)
    {
        height = get_int("Height:"); // re-promting the user if he doesn't co-operate
        
        if (height <= 8 && height >= 1)
        {
            break;
        }
    }
    
    // printing the pyramid
    for (int i = 1; i <= height; i++)   // iterating over the rows
    {
        for (int j = 1; j <= height + 10; j++) //iterating over the columns
        {
            if (i + j < 9 || j == 9 || j == 10)
            {
                printf(" "); //representing the gap or the right part of spaces in the grid above
            }
            
            else if (j > 10 && j > i + 10)
            {
                printf(" "); //representing the left part of spaces in the grid above
            }
            
            else
            {
                printf("#"); //representing the two adjacent pyramids
            }
            
        }
        
        printf("\n");
    }
    
    
}
