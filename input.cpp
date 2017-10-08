#include<fstream>
#include"globals.h"
using namespace std;
void input(void)
{
	ifstream f_input("input.in");
	f_input >> photon_num;
	f_input >> photon_freq;
	f_input >> level_split;
	f_input >> coupling;
}
