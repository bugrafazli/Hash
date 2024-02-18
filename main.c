#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#define CREATE 1 
#define NCREATE 0

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    Key *w = NULL;
    char word[1024];

    /* Hash table where each element is a linked list */
    Key *hash_table[MAXBUCKETS];

    /* Reset memory space */
    memset(hash_table, 0, sizeof(hash_table));

    /* Open the file */
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("%s file not found.\n", argv[1]);
        exit(1);
    }

    /* Read from the file word by word in an infinite loop. 
     * Search for the hash of the word we read, otherwise add it.
     * Finally, increase the count member of the node we have by 1. */
    while (1) {
        if (fscanf(fp, "%s", word) != 1)
            break;

        w = hash_lookup(hash_table, word, CREATE);
        w->count++;
    }

    /* Close the file */
    fclose(fp);

    /* Print words that occur more than 500 times to the screen */
    hash_dump(hash_table, 500);

    /* Clean the hash */
    hash_free(hash_table);
    return 0;
}
