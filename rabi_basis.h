#ifndef RABI_BASIS_H
#define RABI_BASIS_H
#include"quant_num.h"

class Rabi_basis //basis |sigma_z, n >
{
	public:
		Quant_num * quant_num;
		Rabi_basis(int);
		~Rabi_basis();
};
#endif
