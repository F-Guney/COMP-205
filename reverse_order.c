#include <stdio.h>
#include "reverse_order.h"

void reverse_order(void) {
      char input[100] = "";
      printf("Enter file name: ");
      scanf("%s", input);
      FILE *fp;
      char ch;
      int i,pos;
      fp=fopen(input,"r");
      if(fp==NULL)
      {
            printf("File does not exist..");
      }
      fseek(fp,0,SEEK_END);
      pos=ftell(fp);
      //printf("Current postion is %d\n",pos);
      i=0;
      while(i<pos)
       {
            i++;
            fseek(fp,-i,SEEK_END);
            ch=fgetc(fp);
            printf("%c",ch);
      }
      printf("\n");
      
}
