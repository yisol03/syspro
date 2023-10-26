#include <stdio.h>
#include <stdlib.h>
#include "store.h"

int main(int argc, char* argv[])
{
	struct store rec;
	FILE *fp;
	int n;

	fp = fopen(argv[1], "r");
	printf("0: list of all goods, 1: list of availale goods )");
	scanf("%d", &n);
	printf("%2s %15s %8s %12s %5s\n", "id", "name", "category", "expired data", "stock");

	if (n == 0) {
		while (fscanf(fp, "%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.expired, &rec.stock) == 5)
			printf("%2d %15s %8s %12d %5d\n", rec.id, rec.name, rec.category, rec.expired, rec.stock);
	}

	else {
		while (fscanf(fp, "%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.expired, &rec.stock) == 5){
			if (rec.expired > 2022 && rec.stock > 0)
				printf("%2d %15s %8s %12d %5d\n", rec.id, rec.name, rec.category, rec.expired, rec.stock);
		}
	}
	
	fclose(fp);
	exit(0);
}
