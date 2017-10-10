#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<mkl.h>
#include"globals.h"
#include"rabi_basis.h"
#include"hamilt.h"
using namespace std;

Hamilt::Hamilt(int dim_) //constructor.
{
	dim=dim_;
	hamilt_matrix=new double * [dim];
	eig_stat=new double * [dim];
	eig_val=new double [dim];
	for (int i=0;i<dim;i++){
		hamilt_matrix[i]=new double [dim];
		eig_stat[i]=new double [dim];
	}
}

Hamilt::~Hamilt() //destructor.
{
	for (int i=0;i<dim;i++){
		delete [] hamilt_matrix[i];
		delete [] eig_stat[i];
	}
	delete [] hamilt_matrix;
	delete [] eig_stat;
	delete [] eig_val;
}

void Hamilt::calc_hamilt(Rabi_basis & basis_) //get entire hamiltonian matrix.
{
	int flip(int);
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			double part1,part2,part3_1,part3_2;
			part1=photon_freq*basis_.quant_num[j].n*kronecker_delta(basis_.quant_num[i].s,basis_.quant_num[j].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n);
			part2=level_spacing/2.0*basis_.quant_num[j].s*kronecker_delta(basis_.quant_num[i].s,basis_.quant_num[j].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n);
			if (basis_.quant_num[j].n==0){
				part3_1=0;
			}else{
				part3_1=-1.0*coupling*sqrt(basis_.quant_num[j].n)*kronecker_delta(flip(basis_.quant_num[j].s),basis_.quant_num[i].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n-1);
			}
			if (basis_.quant_num[i].n==0){
				part3_2=0;
			}else{
				part3_2=-1.0*coupling*sqrt(basis_.quant_num[j].n+1)*kronecker_delta(flip(basis_.quant_num[j].s),basis_.quant_num[i].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n+1);
			}
			hamilt_matrix[i][j]=part1+part2+part3_1+part3_2;
		}
	}
}

void Hamilt::diag_hamilt() //diagonalize hamiltonian with MKL.
{
	lapack_int n;
	n=dim;
	lapack_complex_double * hamilt1d=new lapack_complex_double [dim*dim];
	{int k=0; //change 1d array hamilt_matrix to 1d array hamilt1d.
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			hamilt1d[k].real = hamilt_matrix[i][j];
			hamilt1d[k].imag = 0;
			k++;
		}
	}}
	// calling MKL to diagonalize.
	lapack_int lda;
	lda=dim;
	double vl,vu;
	lapack_int il,iu;
	double abstol=1e-15; //error tolerance?
	lapack_int * m;
	m=& lda;
	lapack_complex_double * z= new lapack_complex_double [dim*dim];
	lapack_int ldz=dim;
	lapack_int * isuppz = new int [2*dim];
	int info=LAPACKE_zheevr(LAPACK_ROW_MAJOR,'V','A','U',dim,hamilt1d,lda,vl,vu,il,iu,abstol,m,eig_val,z,ldz,isuppz);
	for (int i=0;i<dim;i++){ //getting eigen states in eig_stat.
		for (int j=0;j<dim;j++){
			eig_stat[i][j]=z[i*dim+j].real;
			if ( fabs(z[i*dim+j].imag) > 1e-15){
				cout << "  Error! Hamiltonian is not Hermit." << endl;
			}
		}
	}
}

void Hamilt::print_energy() //print eigen energy to file.
{
	ofstream f_energy("energy.dat");
	for (int i=0;i<dim;i++){
		f_energy << left << setw(6) << i << setprecision(20) << eig_val[i] << endl;
	}
	f_energy.close();
}

int flip(int s) //flip the spin in basis.
{
	if (s==1){
		return -1;
	}else if (s==-1){
		return 1;
	}
}

void Hamilt::print_matrix() //print hamilt_matrix elements.
{
	cout << "matrix" << endl;
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			cout << hamilt_matrix[i][j] << endl;
		}
	}
}

double Hamilt::print_Eg() //print groud state energy.
{
	return eig_val[0];
}
