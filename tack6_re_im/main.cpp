#include <iostream>
#include "CMP.h"
using namespace std;
void test()
{
	float re1 = 2.1;
	float im1 = 3.2;
	float re2 = 1.1;
	float im2 = 3.0;
	CMP compl1(re1, im1);
    CMP compl2(re2, im2);
	CMP result_operations;
	CMP result_div_zero;
	float result_re, result_im;
	result_im = re1*im2 + re2*im1 + im1;
	result_re = re1*re2 - im1*im2 + re1;
	result_operations = compl1 * compl2 + compl1;
	cout << result_operations;
	if (abs(result_operations.im - result_im)>0.00003 && abs(result_operations.re - result_re)>0.00003)
		printf("error: results: %f %f", result_operations.im, result_im);
	try{
	result_div_zero = compl2 / CMP();
	printf("error by division");
	}
	catch (char* str){
	};
}
int main() {
	test();
	CMP Example(5, 7);
	cout << Example << endl;
	CMP Example2(-3, -8);
	cout << Example2 << endl;
	system("pause");
	return 0;
}
