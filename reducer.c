#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAXCHAR 100000
struct Tuples {
  char userID[5];
 // char action;
  char topic[16];
  int score;
};
int main(int argc, char * * argv) {
 
  const char s[4] = "()";
  const char newLine[4] = "\n";
  const char comma[2] = ",";
  char *token;
  struct Tuples inputTuple[1000]={0};
  int j = 0, i = 0, init = 0, k = 0, addVal = 0;
  char str[MAXCHAR];
  char *userId;
  char *topic;
  char *score;
  
  printf("enter the input for reducer");

  int index = 0;
  while (fgets(str, 40, stdin) != NULL) {
    token = strtok(str, s);  
    userId = strtok(token, comma);
    topic = strtok(NULL, comma);
    score = strtok(NULL, ")");
   
    for(i=0;i<4;i++)
        {
    inputTuple[index].userID[i]=userId[i];}
    for(i=0;i<15;i++)
    {
    inputTuple[index].topic[i]=topic[i];}
    
    inputTuple[index].score=atoi(score);
   
    if(index>0 && (strcmp(inputTuple[index].userID, inputTuple[index-1].userID))!=0)
    {  
      for(i=0;i<=index;i++)
      {
    	for(k=i+1;k<=index;k++)
    	{ 
              if((strcmp(inputTuple[i].userID, inputTuple[k].userID)==0)&& (strcmp(inputTuple[i].topic, inputTuple[k].topic)==0))
          {   
              addVal=inputTuple[i].score+inputTuple[k].score;
               
              inputTuple[i].score=addVal;
              
          for(j=k;j<=index-1;j=j+1)
          {   
               inputTuple[j]=inputTuple[j+1];
          }

          index=index-1;
          k=k-1;
          }    

       
    	} 

      }

           for (i = 0; i < index; i = i +1 )
                 {
                   printf("\n%s,%s,%d", inputTuple[i].userID, inputTuple[i].topic, inputTuple[i].score);
                 
                  }
          printf("\ncontinue printing tuples:");

    }
    index++;

  }

        for(i=0;i<index;i++)
      {
    	for(k=i+1;k<index;k++)
    	{ 
              if((strcmp(inputTuple[i].userID, inputTuple[k].userID)==0)&& (strcmp(inputTuple[i].topic, inputTuple[k].topic)==0))
          {   
              addVal=inputTuple[i].score+inputTuple[k].score;
               
              inputTuple[i].score=addVal;
              
          for(j=k;j<index-1;j=j+1)
          {   
               inputTuple[j]=inputTuple[j+1];
          }

          index=index-1;
          k=k-1;
          }    

       
    	} 

      }


  
  printf("\n-------------------------------------------------------------------------");
  printf("\nFinal Output of reducer");
  for (i = 0; i < index; i = i +1 ) {
    
    printf("\n(%s,%s,%d)", inputTuple[i].userID, inputTuple[i].topic, inputTuple[i].score);
  }

 
  printf("\n program execution completed\n");
  return 0;
}
