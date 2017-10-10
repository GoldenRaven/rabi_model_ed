#include<iostream>
#include<iomanip>
#include"globals.h"
#include"rabi_basis.h"
#include"quant_num.h"
using namespace std;

Rabi_basis::Rabi_basis(int n) //constructor.
{
	num=n;
	int zero2downarrow(int);
	quant_num=new Quant_num [num];
	int k=0;
	for (int i=0;i<2;i++){
		for (int j=0;j<photon_num+1;j++){
			quant_num[k].init(zero2downarrow(i),j);
			k++;
		}
	}
}

Rabi_basis::~Rabi_basis() //destructor.
{
	delete [] quant_num;
}

int zero2downarrow(int i) //change zero to -1.
{
	if (i == 0 ){
		return -1;
	}else{
		return 1;
	}
}

void Rabi_basis::print_basis() //print basis.
{
	cout << setw(10) << left << "sigma_z" << setw(10) << left << "n" << endl;
	for (int i=0;i<num;i++){
		cout << setw(10) << left << quant_num[i].s << setw(10) << left << quant_num[i].n << endl;
	}
}
