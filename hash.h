#ifndef _HASH_H
#define _HASH_H

#define MAXBUCKETS 1000

typedef struct key {
  char* word;
  unsigned long count;
  struct key *next;
} Key;

unsigned long hash_compute(const char *str);
Key* hash_lookup(Key **table, const char *str, int create);
void hash_free(Key **table);
void hash_dump(Key **table,int n);

#endif
