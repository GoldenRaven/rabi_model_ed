#include"globals.h"
int photon_num;
double photon_freq;
double level_spacing;
double coupling;

int kronecker_delta(int a, int b)
{
	if (a==b){
		return 1;
	}else{
		return 0;
	}
}
