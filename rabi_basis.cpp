#include"globals.h"
#include"rabi_basis.h"
#include"quant_num.h"

Rabi_basis::Rabi_basis(int n)
{
	int zero2downarrow(int);
	quant_num=new Quant_num [n];
	int k=0;
	for (int i=0;i<2;i++){
		for (int j=0;j<photon_num+1;j++){
			quant_num[k].init(zero2downarrow(i),j);
			k++;
		}
	}
}

Rabi_basis::~Rabi_basis()
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
