#include <stdio.h>
#include <stdlib.h>
#include "Prisoner.h"
#include "PrisonerPlayers.h"
#include <assert.h>

/*For best output, don't pick a length larger than 99
But if you do, change SPACES accordingly in prisoneraesthetics
*/

/*How long each game is*/
#define GAMELENGTH 20

/*Do you want to save the results to a file?*/
#define SAVE_RESULTS_TO_FILE 1

/*What do you want to name the file*/
#define FILE_NAME "PrisonerTest.txt"

/*How many games should there be*/
#define NUMBER_OF_ROUNDS 10

/*Print results to STDOUT?*/
#define PRINT_RESULTS 1

int
main(int argc, char *argv[]){

	assert(GAMELENGTH > 1);
	assert(NUMBER_OF_ROUNDS > 1);
	int (*p1)(int*, int*, int);
	int (*p2)(int*, int*, int);
	void (*scorer)(int, int, int*) = &score;


	print_welcome_message();

	/*SET YOUR PLAYERS HERE*/
	p1 = &titfortat;
	p2 = &yolo;

	tournament(*p1, *p2, *scorer, NUMBER_OF_ROUNDS, GAMELENGTH, SAVE_RESULTS_TO_FILE, FILE_NAME, PRINT_RESULTS);
	return 0;
}
