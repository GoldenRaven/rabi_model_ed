#include<iostream>
#include<iomanip>
#include"globals.h"
using namespace std;

void output(void)
{
    cout << "  parameters:    " << endl;
    cout << "    photon_num:    " << setw(10) << photon_num << endl;
    cout << "    photon_freq:   " << setw(10) << photon_freq << endl;
    cout << "    level_spacing: " << setw(10) << level_spacing << endl;
    cout << "    coupling:      " << setw(10) << coupling << endl;
    cout << endl;
}
