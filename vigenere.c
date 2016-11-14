#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char c, int key);

int main(int argc, string argv[]) {

    
    string keyword = "";
    int klength = 0;
    string text = "";
    int counter = 0;
    int text_length;
    bool suc = false;
    
    do
    {
        if(argc != 2)
        {
            printf("Wrong command line argument \n");
           return 1;
        }
        else 
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {
                if(!isalpha(argv[1][i]))
                {
                    printf("You have typed invalid characters \n");
                    return 1;
                }
                else
                {
                      suc = true;
                      keyword = argv[1];
                }    
            }
        }
    } while(!suc);
  
klength = strlen(keyword);
int keycodes[klength];

for(int i = 0; i < klength;i++)
{
      keycodes[i] = toupper(keyword[i]) - 65;
}


text = GetString();
text_length = strlen(text);

for (int i = 0; i < text_length; i++)
{
    if(!isalpha(text[i]))
     {
         printf("%c", text[i]);
     }

    else
    {
      printf("%c", caesar(text[i], keycodes[counter]));
  
            if(counter < klength - 1)
            {
               counter++;
            }
            else
            {
                counter = 0;
            }
        }
    }
    return 0;
}

char caesar(char c, int key)
{
   if(isalpha(c))
        {
     
           return ((((c - 96)+key)%26)+96);
    }
    else
    {
        return ((((c - 65)  +key)%26)+65);
    }
}
