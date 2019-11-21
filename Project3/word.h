// Word functions
struct Word* word(char* word, int count, struct Word* next);
void setNext(struct Word* curr, struct Word* word);
struct Word* getNext(struct Word* curr);
int incrWord(struct Word* list, char* word);
char* getWord(struct Word* curr);
void printWords(struct Word* list);
int getCount(struct Word* curr);
void plusCount(struct Word* curr);
void setWord(struct Word* curr, char ch[]);
