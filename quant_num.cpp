#include<iostream>
#include"globals.h"
#include"quant_num.h"

Quant_num::Quant_num()
{
	//std::cout << "default construcror called" << std::endl;
	sigma_=-9;
	photon_n_=-9;
}

void Quant_num::init(int sigma, int photon_n)
{
	sigma_=sigma;
	photon_n_=photon_n;
}
