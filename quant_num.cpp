#include<iostream>
#include"globals.h"
#include"quant_num.h"

Quant_num::Quant_num()
{
	//std::cout << "default construcror called" << std::endl;
	s=-9;
	n=-9;
}

void Quant_num::init(int sigma, int photon_n)
{
	s=sigma;
	n=photon_n;
}
