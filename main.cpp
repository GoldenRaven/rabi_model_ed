#include<iostream>
#include"globals.h"
#include"rabi_basis.h"
#include"hamilt.h"
void date();
void input();

using namespace std;
int main()
{
	cout << "Jobs started on: ";date();cout << endl;
	input(); // input parameters from file.
	int basis_num;
	basis_num=2*(photon_num+1); //number of entire basis.
	Rabi_basis basis(basis_num); //generate basis.
	Hamilt hamilt(basis_num); //define hamiltonian.
	hamilt.calc_hamilt(basis); //calculate hamiltonian matrix.
	hamilt.diag_hamilt(); //calling MKL to diagnolize.
	hamilt.print_energy(); //print eigen energy to file "energy.dat".
	cout << "Jobs finished on: ";date();cout << endl;
}
