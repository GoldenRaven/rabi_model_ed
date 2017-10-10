#include<iostream>
#include<fstream>
//#include<mkl.h>
#include"globals.h"
#include"rabi_basis.h"
#include"operator.h"
void date();
void input();

using namespace std;
int main()
{
	cout << "Jobs started on: ";date();cout << endl;
	input(); // input parameters from file.
	int basis_num;
	basis_num=2*(photon_num+1);
	Rabi_basis basis(basis_num); //generate basis.
	Operator hamil(basis_num);
	hamil.calc_hamil(basis);
	double vl,vu;
	int il,iu;
	double abstol=1e-9; //error tolerance?
	int ldz=basis_num;
	double * value= new double [basis_num];
	int * isuppz = new int [2*basis_num];
	int info=LAPACKE_zheevr(LAPACK_ROW_MAJOR,'V','A','U',basis_num,temp,basis_num,vl,vu,il,iu,abstol,basis_num,value,vect_temp,ldz,isuppz);
	cout << "Jobs finished on: ";date();cout << endl;
}
