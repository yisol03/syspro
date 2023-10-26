#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char c[100];
	if (argc < 2)
		fp = stdin;
	else  fp = fopen(argv[1],"r");

	for(int i=0; i<2; i++){
		fgets(c, 100, fp);
		printf("%s", c);
	}
	fclose(fp);
	return 0;
}
