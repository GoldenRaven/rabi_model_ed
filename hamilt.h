#ifndef HAMILT_H
#define HAMILT_H
#include"rabi_basis.h"

class Hamilt //hamiltonian matrix.
{
	public:
		int dim;
		double ** hamilt_matrix;
		double ** eig_stat;
		double *  eig_val;
		Hamilt(int);
		~Hamilt();
		void calc_hamilt(Rabi_basis &);
		void diag_hamilt();
		void print_energy();
};
#endif
