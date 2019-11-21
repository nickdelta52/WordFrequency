#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

// Word struct
struct Word {
  char* word;
  int count;
  struct Word* next;
};

// Word constructor
struct Word* word(char* word, int count, struct Word* next) {
  struct Word* w;
  w = (struct Word*) malloc(sizeof(struct Word*));
  w->word = word;
  w->count = count;
  w->next = next;
  return w;
}

// Prints out formated list of word frequency
void printWords(struct Word* list) {
  struct Word* temp = list;
  int leng = 0;
  while (getWord(temp)!=NULL) {
    leng = strlen(getWord(temp));
    int i = 15 - leng;
    printf("%s: %*i\n", getWord(temp), i,  getCount(temp));
    temp = getNext(temp);
  }
  printf("%s\n", "|----------------------------------------|");
}

// Increments word count within list
int incrWord(struct Word* list, char word[]) {
  while (getWord(list)!=NULL) {
    if (!strcmp(getWord(list), word)) {
      list->count++;
      return 1;
    }
    list = getNext(list);
  }
  return 0;
}

// Word setter
void setWord(struct Word* curr, char ch[]) {
  if (curr != NULL) {
    curr->word = (char*)ch;
  } else {
    curr->word = NULL;
  }
}

// Word getter
char* getWord(struct Word* curr) {
  if (curr != NULL) {
    return curr->word;
  } else {
    return NULL;
  }
}

// Count getter
int getCount(struct Word* curr) {
  if (curr != NULL) {
    return curr->count;
  } else {
    return 0;
  }
}

// Increments count
void plusCount(struct Word* curr) {
  curr->count++;
}

// Next getter
struct Word* getNext(struct Word* curr) {
  if (curr->next != NULL) {
    return curr->next;
  } else {
    return NULL;
  }
}

// Next setter
void setNext(struct Word* curr, struct Word* word) {
  curr->next = word;
}
