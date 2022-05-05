#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "hangman.h"
#include "graphic.h"

#define SPELL_FILE_NAME "spell_collection.txt"
#define MAX_SCORE 7

int main(void)
{	system("clear");
	load_screen();
	int spell_size = 0, correct_ans = 0, wrong_ans = 0;
	char ch, *word;
	int wlen = 0, pos, i;

	spell_size = init_game(SPELL_FILE_NAME);
	if (spell_size < 0) {
		printf("[ERROR] Failed to initialize HangMan, Exiting...\n");
		return -1; 
	}
	sleep(1);
	while (correct_ans <= 7 || wrong_ans <= 7)
	{
		system("clear");
		graphic(wrong_ans, correct_ans);
		printf("===========================\n");
		printf("SCORE [W=%d, C=%d ]\nWORD:\n", wrong_ans, correct_ans);
		word = get_random_word(spell_size);	
		wlen = strlen(word) - 1;

		pos = rand() % wlen;
		
		for (i = 0; i <= wlen; i++) {
			if (i != pos)
				putchar(word[i]);
			else
				putchar('_');
		}

		printf("\nEnter:\n");
		scanf("%c", &ch);
		getchar();

		if (ch == word[pos]) {
			correct_ans++;
			printf("CORRECT\n");
		} else {
			wrong_ans++;
			printf("WRONG\n");
		}

		printf(":Wrong = %d, Correct = %d\n", wrong_ans, correct_ans);
		system("clear");
		if (wrong_ans >= 7) {
			graphic(wrong_ans, correct_ans);
			losser_screen();
			printf(":Wrong = %d, Correct = %d\n", wrong_ans, correct_ans);
			break;
		} 
		
		if (correct_ans >= 7) {	
			graphic(wrong_ans, correct_ans);
			winner_screen();
			printf(":Wrong = %d, Correct = %d\n", wrong_ans, correct_ans);
			break;
		}
	}	

	return 0;
}
