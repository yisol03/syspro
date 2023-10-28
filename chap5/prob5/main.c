#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main (int argc, char *argv[])
{
	int fd;
	struct student rec;
	if (argc < 2) {
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640)) == -1) {
		perror(argv[1]);
		exit(2);
	}

	printf("%-9s %-8s %-4s\n", "StuID", "Name", "Score");
	while (scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3) {
		lseek(fd, (rec.id - START_ID) * sizeof(rec), SEEK_SET);
		write(fd, (char *) &rec, sizeof(rec));
	}

	close(fd);
	exit(0);
}
