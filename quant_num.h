#ifndef QUANT_NUM_H
#define QUANT_NUM_H
class Quant_num
{
	public:
		int sigma_;//spin eigenvalue
		int photon_n_;//number of photon
		Quant_num();
		void init(int sigma, int photon_n);
		//~Quant_num();
};
#endif
