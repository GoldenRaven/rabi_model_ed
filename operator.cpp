#include<iostream>
#include<math.h>
#include"globals.h"
#include"rabi_basis.h"
#include"operator.h"

Operator::Operator(int dim_)
{
	dim=dim_;
	operator_matrix=new double * [dim];
	for (int i=0;i<dim;i++){
		operator_matrix[i]=new double [dim];
	}
}

Operator::~Operator()
{
	for (int i=0;i<dim;i++){
		delete [] operator_matrix[i];
	}
	delete [] operator_matrix;
}

void Operator::calc_hamil(Rabi_basis & basis_)// n: length of matrix, get entire hamil
{
	int flip(int);
	for (int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){
			int part1,part2,part3_1,part3_2;
			part1=photon_freq*basis_.quant_num[j].n*kronecker_delta(basis_.quant_num[i].s,basis_.quant_num[j].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n);
			part2=level_spacing/2.0*basis_.quant_num[j].s*kronecker_delta(basis_.quant_num[i].s,basis_.quant_num[j].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n);
			if (basis_.quant_num[j].n==0){
				   part3_1=0;
			}else{
				part3_1=sqrt(basis_.quant_num[j].n)*kronecker_delta(flip(basis_.quant_num[j].s),basis_.quant_num[i].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n-1);
			}
			if (basis_.quant_num[i].n==0){
				   part3_2=0;
			}else{
				part3_2=sqrt(basis_.quant_num[j].n+1)*kronecker_delta(flip(basis_.quant_num[j].s),basis_.quant_num[i].s)*kronecker_delta(basis_.quant_num[i].n,basis_.quant_num[j].n+1);
			}
			operator_matrix[i][j]=part1+part2+part3_1+part3_2;
		}
	}
}

int flip(int s) //flip the spin in basis.
{
	if (s==1){
		return -1;
	}else if (s==-1){
		return 1;
	}
}
