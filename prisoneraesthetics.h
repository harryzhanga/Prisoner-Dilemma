#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#define SPACES 3

/*FIX THE PRINTING OUT GAME because 2 digits are still having 1 space*/
void
printgameline(int *numbers, int len, int *sum){
	/*Used in printgame, but is applicable to other things
	Prints out the integers from 'numbers' and calculates the
	sum, putting it into 'sum'*/
	int i;
	*sum = 0;
	for(i=0; i<len; i++){
		printf("%*d ", SPACES, *(numbers+i));
		*sum += *(numbers+i);
	}

	return;
}

void
printgame(int *p1input, int *p2input, int *p1scores, 
	int *p2scores, int gamelength){

	/*Prints out the game*/
	printf("Trial No:        ");
	int i;

	for(i=0; i<gamelength; i++){
		printf("%*d ", SPACES, i+1);
	}
	printf("\n"); 
	printf("Player 1 scores: ");
	int sum = 0;
	printgameline(p1scores, gamelength, &sum);
	printf("=> sum: %d\n", sum);
	
	printf("Player 1  input: ");
	printgameline(p1input, gamelength, &sum);
	printf("=> sum: %d\n", sum);
	
	printf("Player 2  input: ");
	printgameline(p2input, gamelength, &sum);
	printf("=> sum: %d\n", sum);
	
	printf("Player 2 scores: ");
	printgameline(p2scores, gamelength, &sum);
	printf("=> sum: %d\n", sum);

	printf("\n");
}

void
printgamelinefile(int *numbers, int len, int *sum, FILE *fp){
	/*Used in printgame, but is applicable to other things
	Prints out the integers from 'numbers' and calculates the
	sum, putting it into 'sum'*/
	int i;
	*sum = 0;
	for(i=0; i<len; i++){
		fprintf(fp, "%*d ", SPACES, *(numbers+i));
		*sum += *(numbers+i);
	}
	return;
}

void
printgamefile(int *p1input, int *p2input, int *p1scores, 
	int *p2scores, int gamelength, FILE *fp){
	
	/*Prints out the game*/
	
	
	fprintf(fp, "GAME:            ");
	int i;
	for(i=0; i<gamelength; i++){
		fprintf(fp, "%*d ", SPACES, i+1);
	}
	fprintf(fp, "\n"); 
	fprintf(fp, "Player 1 scores: ");
	int sum = 0;
	printgamelinefile(p1scores, gamelength, &sum, fp);
	fprintf(fp, "=> sum: %d\n", sum);
	
	fprintf(fp, "Player 1  input: ");
	printgamelinefile(p1input, gamelength, &sum, fp);
	fprintf(fp, "=> sum: %d\n", sum);
	
	fprintf(fp, "Player 2  input: ");
	printgamelinefile(p2input, gamelength, &sum, fp);
	fprintf(fp, "=> sum: %d\n", sum);
	
	fprintf(fp, "Player 2 scores: ");
	printgamelinefile(p2scores, gamelength, &sum, fp);
	fprintf(fp, "=> sum: %d\n\n", sum);
}