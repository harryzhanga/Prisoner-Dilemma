#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*These are the players, you can design your own!*/

int
silencer(int *you, int *opp, int len){
	return 0;
}

int
defector(int *you, int *opp, int len){
	return 1;
}

int
titfortat(int *you, int*opp, int len){
	if(len==0){
		return 0;
	}
	return *(opp+len-1);
}

int
yolo(int *you, int*opp, int len) {
	srand(time(NULL));
	int random = rand() % 2;
	return random;
}