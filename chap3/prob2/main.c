#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];
void copy(char from[], char to[]);

int main()
{
	int len, max = 0;
	char str[MAXLINE][MAXLINE];
	char temp[MAXLINE];
	
	for(int i=0; i<5; i++)
		scanf("%s", str[i]);

	for(int i=0; i<5; i++){
		for(int j=0; j<5-i; j++){
			if(strlen(str[j]) > strlen(str[j+1])){
				strcpy(temp, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], temp);
			}
		}
	}

   for(int i=0; i<6; i++){
	   printf("%s\n", str[i]);
	}

   return 0;
}
