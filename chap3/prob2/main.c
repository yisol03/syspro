#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];
void copy(char from[], char to[]);

int main()
{
   int len[5], max = 0;

   for(int i=0; i<5; i++){
	  fgets(line,MAXLINE,stdin);
      len[i] = strlen(line);
      if (len[i] > max) {
         max = len[i];
         copy(line, longest);
      }
   }

   for(int i=0; i<5; i++){
	   if (max > 0)
		   printf("%s", longest);
	}


   return 0;
}


