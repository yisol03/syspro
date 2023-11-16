#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*, int, int, int);

int main(int argc, char **argv)
{
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];

    int showInode = 0;
    int showType = 0;
    int showQuote = 0;

    // -i, -p, -Q 옵션 처리
    if(argc == 2 && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "-Q") == 0))
    {
        if(strcmp(argv[1], "-i") == 0)
            showInode = 1;
        else if(strcmp(argv[1], "-p") == 0)
            showType = 1;
        else if(strcmp(argv[1], "-Q") == 0)
            showQuote = 1;

        dir = ".";
    }
    else if(argc == 3 && (strcmp(argv[2], "-i") == 0 || strcmp(argv[2], "-p") == 0 || strcmp(argv[2], "-Q") == 0))
    {
        if(strcmp(argv[2], "-i") == 0)
            showInode = 1;
        else if(strcmp(argv[2], "-p") == 0)
            showType = 1;
        else if(strcmp(argv[2], "-Q") == 0)
            showQuote = 1;

        dir = argv[1];
    }
    else
    {
        dir = argc == 1 ? "." : argv[1];
    }

    if((dp = opendir(dir)) == NULL)
    {
        perror(dir);
        exit(EXIT_FAILURE);
    }

    while((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dir, d->d_name);
        if(lstat(path, &st) < 0)
            perror(path);
        else
            printStat(path, d->d_name, &st, showInode, showType, showQuote);
    }

    closedir(dp);
    exit(EXIT_SUCCESS);
}

void printStat(char *pathname, char *file, struct stat *st, int showInode, int showType, int showQuote)
{
    printf("%5ld ", st->st_blocks);

    if(showInode)
        printf("%lu ", (unsigned long)st->st_ino);

    printf("%c%s", type(st->st_mode), perm(st->st_mode));


    if(showType)
    {
        if (S_ISDIR(st->st_mode)) {
            printf("/");
        } else if (S_ISLNK(st->st_mode)) {
            printf("@");
        } else if (S_ISSOCK(st->st_mode)) {
            printf("=");
        } else if (S_ISFIFO(st->st_mode)) {
            printf("|");
        }
    }

    printf(" %3ld ", st->st_nlink);
    
    struct passwd *pwd = getpwuid(st->st_uid);
    struct group *grp = getgrgid(st->st_gid);
    if(pwd != NULL && grp != NULL)
    {
        printf("%s %s ", pwd->pw_name, grp->gr_name);
    }
    else
    {
        printf("Unknown Unknown ");
    }

    printf("%9ld ", st->st_size);
    printf("%.12s ", ctime(&st->st_mtime)+4);
    if(showQuote)
        printf(" \"%s\"", file);
    else
        printf(" %s", file);
    printf("\n");
}

char type(mode_t mode)
{
    if (S_ISREG(mode))
        return ('-');
    if (S_ISDIR(mode))
        return ('d');
    if (S_ISCHR(mode))
        return ('c');
    if (S_ISBLK(mode))
        return ('b');
    if (S_ISLNK(mode))
        return ('l');
    if (S_ISFIFO(mode))
        return ('p');
    if (S_ISSOCK(mode))
        return ('s');

    return ('?');
}

char *perm(mode_t mode)
{
    static char perms[10];
    strcpy(perms, "---------");

    for (int i = 0; i < 3; i++)
    {
        if (mode & (S_IRUSR >> i * 3))
            perms[i * 3] = 'r';
        if (mode & (S_IWUSR >> i * 3))
            perms[i * 3 + 1] = 'w';
        if (mode & (S_IXUSR >> i * 3))
            perms[i * 3 + 2] = 'x';
    }

    return (perms);
}
