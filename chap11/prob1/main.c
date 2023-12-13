#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //alarm(5);
    printf("Loop start\n");
    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
	if(i == 4)
		break;
    }
    printf("Alarm clock\n");

    return 0;
}

