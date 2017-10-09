#include<iostream>
#include<fstream>
#include"globals.h"
#include"rabi_basis.h"
using namespace std;
void generate_basis(void)
{
	Rabi_basis basis;
	for (int i=0;i<2*(photon_num+1);i++){
		cout << basis.quant_num[i].sigma_ << "   " << basis.quant_num[i].photon_n_ << endl;
	}
	//cout << basis.quant_num[1].photon_n_ << endl;
}
