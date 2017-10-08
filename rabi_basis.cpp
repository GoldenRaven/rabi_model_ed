#include"globals.h"
#include"rabi_basis.h"
#include"quant_num.h"
using namespace std;

Rabi_basis::Rabi_basis(Quant_num * quant_num ,int n)
{
	quant_num=new Quant_num [n];
}

Rabi_basis::~Rabi_basis()
{
	delete [] quant_num;
}
