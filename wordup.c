//Ngan Tuyet Ong
//Project 10

#include <stdio.h>
#include <stdbool.h>
#define word 5
#define attempt 6
#define filein "mystery.txt"
#define FILEIN "guesses.txt"

//function 1: finds word that will be guessed
void enterword (char answer []);
//function 2: prompts for and collects up to 6 guesses from the user
void guesswords (char answer [], char guess [][word], char correction [][word]);
//function 3: change and store all guesses to lowercase only
void lowercase (char guess [][word], int i, int k);
//function 4: changes letters in the correct position to uppercase
//function 5: points to letters that are in the word, but in wrong position
//function 6: resets guesses txt to blank

int main (){
char answer[word], guess[attempt][word], correction [attempt][word];
	enterword (answer);
	guesswords (answer, guess, correction);
return 0;
}

void enterword (char answer []){
FILE* readfile;
	readfile = fopen(filein, "r");
		if (readfile == NULL){
			printf("Error: Answer word file could not be opened!");
			return;
		}
	fscanf(readfile, "%s", answer);
fclose(readfile);
}
void guesswords (char answer [], char guess [][word], char correction [][word]){
int correct;
FILE* writefile;
	writefile = fopen(FILEIN, "w");
		if (writefile == NULL){
			printf("Error: Answer word file could not be opened!");
			return;
		}
	int i = 0, k = 0;
	do{
		printf("GUESS %d! Enter your guess: ", i + 1);
		scanf("%s", &guess[i]);
		printf("================================\n");
		lowercase (guess, i, k);
	for (k = 0; guess[i][k] != '\0'; k++){
		if (guess[i][k] != answer[k]){
			correct++;
			}
		else {
			correct = 0;
			}
			}
		i++;
		fprintf(writefile, "%s\n", guess[i]);
		fprintf(writefile, "%s\n", correction[i]);
	}while (i < attempt && correct != 4);
fclose(writefile);
}
void lowercase (char guess [][word], int i, int k){
	for (k = 0; guess[i][k] != '\0'; k++){
		if (guess[i][k] >= 'A' && guess[i][k] <= 'Z'){
			guess[i][k] = guess[i][k] + 32;
		}
	}
}
