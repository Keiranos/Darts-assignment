#include "Dartboard.h"
#include <stdlib.h>

int Dartboard::throw_single(int d, int p) {
	// This function has been taken from the sample darts functions we were provided with on MLS: https://mylearningspace.abertay.ac.uk/d2l/le/content/22672/viewContent/399708/View
	//  return result of throwing for single d with accuracy 88% (or 80% for the outer bullseye)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;

	if (d == 25) {		// outer bullseye has success rate of 80%
		if (r <= p)
			return 25;
		else
			return rand() % 20 + 1;
	}
	else			// we must be aiming for 1 to 20 single
		if (r <= 88)
			return d;
		else if (r <= 92)
			return bd[0][d];
		else if (r <= 96)
			return bd[1][d];
		else if (r <= 98)
			return 3 * d;
		else
			return 2 * d;
}