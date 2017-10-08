#ifndef RABI_BASIS_H
#define RABI_BASIS_H
#include"quant_num.h"

class Rabi_basis
{
	public:
		Quant_num * quant_num;
		Rabi_basis();
		Rabi_basis(Quant_num * quant_num ,int n_);
		~Rabi_basis();
};
#endif
