#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "include/fileManager.h"


void callBuilder(char *files, char *buildName) {
  char command[999999] = "gcc";
  searchFiles(".", files);

  strcat(command, files);
  
  // if buildName isn't null
  if(strcmp(buildName, "")) {
    strcat(command, " -o ");
    strcat(command, buildName);
  }
  
  system(command);

  exit(0);
}


void searchFiles(char *path, char *text) {
  DIR *dir;
  struct dirent *entry;

  if (!(dir = opendir(path)))
    return;

  while ((entry = readdir(dir)) != NULL) {
    char subpath[1024];
    snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
    struct stat statbuf;
    stat(subpath, &statbuf);
    if (S_ISDIR(statbuf.st_mode)) {
      // it's a dir
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;
      searchFiles(subpath, text);
    } else {
      // it's a file
      if (strstr(entry->d_name, ".c") != NULL) {
        strcat(text, " ");
        strcat(text, path);
        strcat(text, "/");
        strcat(text, entry->d_name);
      }
    }
  }

  closedir(dir);
}
