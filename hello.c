#include <stdio.h>
#include<cs50.h>
#include<string.h>

//this program prompts the user for his/her name and then prints hello followed by that name 

int main(void)
{
    string name = get_string("what's your name?\n"); //prompt for the name
    
    printf("hello, %s\n", name); //prints hello, *name*
}
