all: hangman

hangman: main.c hangman.c hangman.h graphic.c graphic.h
	gcc main.c hangman.c graphic.c -o hangman

clean:
	rm hangman
