#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000


 FILE * fPtr;
 FILE * fTemp;

   char *oldWord=NULL ,*newWord=NULL;

   char buff[BUFFER_SIZE];


 int replica(char *oldWord,char *newWord);
void replaceAll(char *str, char *oldWord, char *newWord);

int main()
{





   char *str[1000];
    char *str1[1000];
  int i=0;

   int j=0;







    FILE *fp = fopen("french_dictionary.csv","r");

   fPtr  = fopen("t8.shakespeare.txt", "r");
    fTemp = fopen("replace.txt", "w");

   if (fPtr == NULL || fTemp == NULL)
    {
       printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }




    if(!fp){
        printf("error occured");
        return 0;
    }
    else{
           char buffer[1024];


        int row = 0;
        int column = 0;


        while (fgets(buffer,1024, fp)) {
            column = 0;
            row++;
            int i=0,j=0;
            if (row == 1)
                continue;
            char* value = strtok(buffer, ", ");






            while (value)
{


                if (column == 0) {
                    str[i]=value;

                   oldWord=str[i];

                    i++;






                }
                if (column == 1) {

                    str1[j]=value;
                    newWord=str1[j];
                    j++;





                }





                value = strtok(NULL, ", ");
                column++;





            }





              replica(oldWord,newWord);
              printf("\n");


            }









}
}






    int replica(char *oldWord,char *newWord)
    {


    while ((fgets(buff, BUFFER_SIZE, fPtr)) != NULL)
    {
        printf("%s %s",oldWord,newWord);
        replaceAll(buff, oldWord, newWord);
            fputs(buff, fTemp);

    }
	
    rename("replace.txt", "t8.shakespeare.txt");

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);

    return 0;

    }











    void replaceAll(char *str,  char *oldWord, char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);
	
    if (!strcmp(oldWord, newWord)) {
        return;
    }

    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);

        index = pos - str;

        str[index] = '\0';

        strcat(str, newWord);

        strcat(str, temp + index + owlen);


    }
}