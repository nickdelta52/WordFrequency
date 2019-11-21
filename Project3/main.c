// Nicholas Basti
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include "word.h"

// functions/global variables
extern char** environ;
typedef struct Word* sWord;
void parse(struct Word* list, char* str);
int contains(sWord lst, char wrd[]);
sWord addNext(sWord lst, char wrd[]);
void strLwr(char* s);

// Main
int main(int argc, char const *argv[]) {
  int in[argc];

  // Deals with environment variable
  int argc1 = argc;
  int cEnv = 0;
  char* env = malloc(sizeof(char*)*20);
  strcpy(env, environ[0]);
  strtok(env, "=");
  if (!strcmp(env, "WORD_FREAK")) {
    //printf("%s\n", "facts");
    cEnv = 1;
    argc1++;
  }
  // Loops through each text file
  for (int i=1; i<argc1; i++) {
    // Checks if accessing env variable or argv
    if (cEnv == 0) {
      in[i] = open(argv[i], O_RDONLY);
    } else {
      in[i] = open(strtok(NULL, " "), O_RDONLY);
    }

    // Make frequency list, word to parse, and char buffer
    sWord list = word(NULL, 1, NULL);
    char tword[100];
    char* buf = malloc(sizeof(char*));

    // Reads each word into buffer and parses into frequency list
    while (read(in[i], buf, 1)) {

      // If buf char is letter add to word
      // Else parses word
      if (isalpha(*buf)) {
        strcat(tword, buf);
      } else if (strcmp(tword, "")) {
        strLwr(tword);
        char* wrd = malloc(sizeof(char*)*1000);
        strcpy(wrd, tword);

        // If first item, set word
        // If contains word increment
        // Else adds word to list
        if (getWord(list) == NULL) {
          setWord(list, wrd);
        } else if (contains(list, wrd)){
          incrWord(list, wrd);
        } else {
          addNext(list, wrd);
        }
        strcpy(tword, "");
      }
      lseek(in[i], 0, SEEK_CUR);

    }

    //printf("%s\n", "DONE");
    printWords(list);
    close(in[i]);
    free(buf);
  }

  return 0;
}

// Converts string to lower case
void strLwr(char* s) {
  int i = 0;
  while (s[i]!='\0') {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i] + 32;
    }
    ++i;
  }
}

// Checks if list contains word
int contains(sWord lst, char wrd[]) {
  sWord temp = lst;
  while (getWord(temp) != NULL) {
    if (!strcmp(getWord(temp), wrd)) {
      return 1;
    }
    temp = getNext(temp);
  }
  return 0;
}

// Adds word to end of list
sWord addNext(sWord lst, char wrd[]) {
  sWord ret = lst;
  struct Word* temp = word(wrd, 1, NULL);

  while (getWord(lst) != NULL) {
    if (getNext(lst)==NULL) {
      setNext(lst, temp);

      return ret;
    }
    lst = getNext(lst);
  }
  return ret;
}
