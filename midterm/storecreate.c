#include <stdio.h>
#include <stdlib.h>
#include "store.h"

int main(int argc, char* argv[])
{
	struct store rec;
	FILE *fp;

	fp = fopen(argv[1], "wb");
	printf("%2s %4s %8s %12s %5s\n", "id", "name", "category", "expired data", "stock");

	while (scanf("%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.expired, &rec.stock) == 5)
		fprintf(fp, "%d %s %s %d %d\n", rec.id, rec.name, rec.category, rec.expired, rec.stock);

	fclose(fp);
	exit(0);
}
