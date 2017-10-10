#include<iostream>
#include<iomanip>
#include"globals.h"
#include"rabi_basis.h"
#include"hamilt.h"
void date();
void input();
void output();

using namespace std;
int main()
{
	cout << "Jobs started on: ";date();cout << endl;
	input(); // input parameters from file.
	output();
	int basis_num;
	basis_num=2*(photon_num+1); //number of entire basis.
	Rabi_basis basis(basis_num); //generate basis.
	//basis.print_basis();
	Hamilt hamilt(basis_num); //define hamiltonian.
	hamilt.calc_hamilt(basis); //calculate hamiltonian matrix.
	//hamilt.print_matrix();
	hamilt.diag_hamilt(); //calling MKL to diagnolize.
	hamilt.print_energy(); //print eigen energy to file "energy.dat".
	cout << "    groud state energy:      " << setw(10) << setprecision(20) << hamilt.print_Eg() << endl;
	cout << "Jobs finished on: ";date();cout << endl;
}
