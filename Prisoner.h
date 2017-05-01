#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prisoneraesthetics.h"
/*Scores given to results*/
#define BOTHDEFECT 2
#define BOTHSILENT 3
#define ONEDEFECT 4
#define OTHERDEFECT 1

void 
print_welcome_message() {
	printf("******************Welcome to Prisoners, the social experiment*******************************\n");
	printf("********In this game, a 0 represent remaining silent and 1 represents defecting*************\n\n");
	return;
}

void
score(int p1, int p2, int *scores){
	/*Scores is a pointer to 2 integers. First one
	is p1's score and the next is p2's score. The scores
	are put into there based on p1 and p2's choices*/
	if(p1 == 1 && p2 == 1){
		*(scores) = *(scores+1) = BOTHDEFECT;
		return;
	}
	if(p1 == 1 && p2 == 0){
		*(scores) = ONEDEFECT;
		*(scores+1) = OTHERDEFECT;
		return;
	}
	if(p1 == 0 && p2 == 1){
		*(scores) = OTHERDEFECT;
		*(scores+1) = ONEDEFECT;
		return;
	}
	if(p1 == 0 && p2 == 0){
		*(scores) = *(scores+1) = BOTHSILENT;
		return;
	}
	printf("ERROR WITH INPUT SCORES!\n");
}


void
prisonermaster(int p1(int*, int*, int), int p2(int*, int*, int),
	int *p1input, int *p2input, int gamelength, 
	int *p1scores, int *p2scores, 
	void score(int ,int, int*)){

	/*Essentially plays the game, doing it 'gamelengths' no of times.
	The results are put into p1input, p2input, p1scores and p2scores*/
	int i;
	int *currscore = (int*)malloc(sizeof(int)*2);
	
	for(i=0; i<gamelength; i++){
		*(p1input+i) = p1(p1input, p2input, i);
		*(p2input+i) = p2(p2input, p1input, i);
		score(*(p1input+i), *(p2input+i), currscore);
		*(p1scores+i) = *currscore;
		*(p2scores+i) = *(currscore+1);

	}
}

void
tournament(int p1(int *, int*, int), int p2(int *, int*, int),
	void score(int, int, int*), int rounds, int roundlength, int printfile,
	char *filename, int printstdout){
	/*Takes 2 players and the scoring function*/
	/*Plays the game 'rounds' no of times with each round being
	'roundlength' long. Prints out the results if requires*/
	FILE *fp = fopen(filename, "w");
	int *p1input = (int*)malloc(sizeof(int)*roundlength);
	int *p2input = (int*)malloc(sizeof(int)*roundlength);
	int *p1scores = (int*)malloc(sizeof(int)*roundlength);
	int *p2scores = (int*)malloc(sizeof(int)*roundlength);
	
	int i;
	for(i=0; i<rounds; i++){
		prisonermaster(p1, p2, p1input, p2input, roundlength, p1scores,
			p2scores, score);
		if(printstdout){
			printf("ROUND %d : \n", i+1);
			printgame(p1input, p2input, p1scores, p2scores, roundlength);
		}
		if(printfile){
			fprintf(fp, "ROUND %d : \n", i+1);
			printgamefile(p1input, p2input, p1scores, p2scores, 
				roundlength, fp);
		}
	}
	fclose(fp);
}
			
	