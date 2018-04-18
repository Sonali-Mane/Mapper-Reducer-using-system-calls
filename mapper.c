#include<stdio.h>
#include <string.h>



int main(int argc, char **argv)
{

    const char s[4] = "()";
     const char comma[2] = ",";
    char *token;
    FILE *fp,*fw;
    int j=0,i,init=0;   
    char *wordsToken[500];
    char *eachWord[500];
    char* filename = "input.txt";
    fp = fopen(filename, "r");
   
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

     char *source = NULL;
     long buffer_size = 0;
     if (fp != NULL) {
    /* Go to the end of the file. */
        if (fseek(fp, 0L, SEEK_END) == 0) {
            /* Get the size of the file. */
            long bufsize = ftell(fp);
            if (bufsize == -1) { /* Error */ }

            /* Allocate our buffer to that size. */
            source = malloc(sizeof(char) * (bufsize + 1));
            buffer_size = bufsize;
            /* Go back to the start of the file. */
            if (fseek(fp, 0L, SEEK_SET) != 0) { /* Handle error here */ }

            /* Read the entire file into memory. */
           
           fread(source, sizeof(char), bufsize, fp);
           
        }
        fclose(fp);
    }


    token = strtok(source, s);



 while( token != NULL ) {

      wordsToken[j++] = token;
         
      token = strtok(NULL, s);
   }


    for( i = 0; i <j; i=i+2)
    {   init=0;
        token = strtok(wordsToken[i], comma);

        while( token != NULL ) {
      eachWord[init++] = token;
      token = strtok(NULL, comma);
       }
   if(strcmp("P", eachWord[1])==0)
   {
    printf("(%s,%s,50)\n",eachWord[0],eachWord[2]);
    }
   if(strcmp("L", eachWord[1])==0)
   {
    printf("(%s,%s,20)\n",eachWord[0],eachWord[2]);
    }
    if(strcmp("D", eachWord[1])==0)
   {
    printf("(%s,%s,-10)\n",eachWord[0],eachWord[2]);
    }

     if(strcmp("C", eachWord[1])==0)
   {
    printf("(%s,%s,30)\n",eachWord[0],eachWord[2]);
    }

     if(strcmp("S", eachWord[1])==0)
   {
    printf("(%s,%s,40)\n",eachWord[0],eachWord[2]);
    }
    }

    return 0;
}
