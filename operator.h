#ifndef OPERATOR_H
#define OPERATOR_H
#include"rabi_basis.h"

class Operator //operator matrix.
{
	public:
		int dim;
		double ** operator_matrix;
		Operator(int);
		~Operator();
		void calc_hamil(Rabi_basis &);
};
#endif
