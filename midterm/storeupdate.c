#include <stdio.h>
#include <stdlib.h>
#include "store.h"

int main(int argc, char* argv[]) 
{ 
   struct store rec;
   FILE *fp1;
   FILE *fp2;
   int n;
   while (1) {
	   fp1 = fopen(argv[1], "rw");
	   fp2 = fopen(argv[1], "r");
	   printf("(n): sell one goods ] ");
	   scanf("%d", &n);

	   while (fscanf(fp1, "%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.expired, &rec.stock) == 5){
		   if (rec.id == n){
			   if (rec.expired > 2022 && rec.stock > 0){
				   rec.stock -= 1;
				   fprintf(fp1, "%d", rec.stock);
				   printf("%s (1) has been sold..\n", rec.name);
			   }
			   else if (rec.stock == 0){
				   printf("%s has been sold ooout.. (There is no stock)\n", rec.name);
			   }
			   else if (rec.expired <= 2022){
				   printf("%s cannot be sold beyond its expiration date.\n", rec.name);
			   }
		   }
		   else
			   continue;
	   }

	   printf("%2s %15s %8s %12s %5s\n", "id", "name", "category", "expired data", "stock");
	   while (fscanf(fp2, "%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.expired, &rec.stock) == 5)
		   printf("%2d %15s %8s %12d %5d\n", rec.id, rec.name, rec.category, rec.expired, rec.stock);
   }

   fclose(fp1);
   fclose(fp2);
   return 0;
} 
