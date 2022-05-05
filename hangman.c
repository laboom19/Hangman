#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define MAX_WORDS_SUPPORTED 1000
#define MAX_WORD_LENGTH 16

static char sp_base[MAX_WORDS_SUPPORTED][MAX_WORD_LENGTH];


/* Initialies the game : 
 * 	Read files and load it into the memory.
 * Return :
 * 	Returns size of words allocated into memory or returns error .
 * */
int init_game(char *spell_file)
{
	FILE *sp_file = NULL;
	char buf[MAX_WORD_LENGTH];
	int c = 0, rc;

	// Try to open file
	sp_file = fopen(spell_file, "r");
	if (!sp_file) {
		printf("[ERROR] : Not able to open [%s] file err=%s\n",
				spell_file, strerror(errno));
		rc = -1;
		goto failure;
	}
	
	// Read from file and move it to memory.
	do {
		rc = fscanf(sp_file, "%s\n", buf);	
		if (rc < 0)
			break;
		strcpy(sp_base[c], buf);
		//printf("[INFO] Loaded [%s]\n", sp_base[c]);
		c++;

	} while (rc > 0 || c < MAX_WORDS_SUPPORTED);
	
//	printf("[INFO] Loaded Word Count = %d\n", c);
	rc = c;
failure:

	fclose(sp_file);
	return rc;	
}


char* get_random_word(int max_size)
{	
	return sp_base[rand() % (max_size -1)];		
}
