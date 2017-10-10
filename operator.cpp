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
