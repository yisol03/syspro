#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    char *env_var_name = NULL;

    while ((opt = getopt(argc, argv, "e:ugiip")) != -1) {
        switch (opt) {
			case 'e':
				env_var_name = optarg;
                if (env_var_name != NULL) {
					char *env_var_value = getenv(env_var_name);
					if (env_var_value != NULL) {
						printf("%s=%s\n", env_var_name, env_var_value);
					} 
					else {
						printf("%s is not set.\n", env_var_name);
					}
				} 
				else {
					extern char **environ;
					for (char **env = environ; *env != NULL; env++) {
						printf("%s\n", *env);
					}
				}
				break;

            case 'u':
                printf("My Realistic User ID: %d\nMy valid User ID: %d\n", getuid(), geteuid());
                break;

            case 'g':
                printf("My Realistic Group ID: %d\nMy Valid Group ID: %d\n", getgid(), getegid());
                break;

            case 'i':
                printf("my process number: %d\n", getpid());
                break;

            case 'p':
                printf("my parent's process number: %d\n", getppid());
                break;

            default:
                fprintf(stderr, "Usage: %s [-e env_var_name] [-u] [-g] [-i] [-p]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}
