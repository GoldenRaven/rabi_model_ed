#include<iostream>
#include<fstream>
#include"globals.h"
void date();
void input();
void generate_basis();
using namespace std;
int main()
{
	cout << "Jobs started on: ";date();cout << endl;
	input();
	generate_basis();
	cout << "Jobs finished on: ";date();cout << endl;
}
