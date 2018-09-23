#include<iostream>
#include<time.h>
#include <stdio.h>
using namespace std;
void date(void)
{
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X ",localtime(&t) );
    cout << tmp;
}
