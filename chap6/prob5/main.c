#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>

 char type(mode_t);
 char *perm(mode_t);
 void printStat(char*, char*, struct stat*);

 int main(int argc, char **argv)
 {
     DIR *dp;
     char *dir;
     struct stat st;
     struct dirent *d;
     char path[BUFSIZ+1];


     if (argc == 1)
         dir = ".";
     else dir = argv[1];

     if ((dp = opendir(dir)) == NULL)
        perror(dir);

     while ((d = readdir(dp)) != NULL) {
         sprintf(path, "%s/%s", dir, d->d_name);
         if (lstat(path, &st) < 0)
            perror(path);
         else
             printStat(path, d->d_name, &st);
     }

     closedir(dp);
     exit(0);
 }

 void printStat(char *pathname, char *file, struct stat *st)
 {
     printf("%5ld ", st->st_blocks);
     printf("%c%s ", type(st->st_mode), perm(st->st_mode));
     printf("%3ld ", st->st_nlink);
     printf("%s %s ", getpwuid(st->st_uid)->pw_name,
                 getgrgid(st->st_gid)->gr_name);
     printf("%9ld ", st->st_size);
     printf("%.12s ", ctime(&st->st_mtime)+4);
     printf("%s\n", file);
 }
