#include <iostream>
#include <vector>
#include "Matrix.h"

int main()
{	
	Matrix matrix1({},2,2);
	matrix1.read();
	Matrix matrix2({}, 2,2);
	matrix2.read();
	matrix1.multiply(matrix2);
	matrix1.print();

	return 0;
}