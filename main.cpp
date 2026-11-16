#include <iostream>
#include <vector>

std::vector<std::vector<int>>readMatrix(const int w, const int l){
	std::vector<std::vector<int>>matrix(w, std::vector<int>(l));
	for (int i = 0; i < w; i++){
		for(int j =0; j< l; j++){
			std::cout << "Podaj liczbe:";
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}

std::vector<std::vector<int>>CreateMatrix(){
std::cout << "Podaj szerokosc: ";
	int w;
	std::cin >> w;
	std::cout << "Podaj dlugosc: ";
	int l;
	std::cin >> l;
	std::vector<std::vector<int>>matrix(w, std::vector<int>(l));
	matrix = readMatrix(w,l);
	return matrix;
}

std::vector<std::vector<int>>AddMatrix(
	const std::vector<std::vector<int>>&matrix1,
	const std::vector<std::vector<int>>&matrix2){
	int w1 = matrix1.size();
	int w2 = matrix2.size();
	int l1 = matrix1[0].size();
	int l2 = matrix2[0].size();
	std::vector<std::vector<int>>matrix(w1, std::vector<int>(l1));
	if (w1 == w2 and l1 == l2){
		for (int i = 0; i < w1; i++){
			for (int j = 0; j < l1; j++){
				matrix[i][j] = matrix1[i][j]+ matrix2[i][j];
			}
		}
	}else{
		std::cout << "Nie mozna dodac macierzy";
	}
	return matrix;
}

std::vector<std::vector<int>>MultiplyMatrix(
	const std::vector<std::vector<int>>&matrix1,
	const std::vector<std::vector<int>>&matrix2){
	int w1 = matrix1.size();
	int w2 = matrix2.size();
	int l1 = matrix1[0].size();
	int l2 = matrix2[0].size();
	std::vector<std::vector<int>>matrix(w1, std::vector<int>(l2));
	if (l1 == w2){
		for (int i = 0; i < w1; i++){
			for (int j = 0; j < l2; j++){
				for(int k = 0; k < w1; k++){
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}
	}else{
		std::cout << "Nie mozna pomnozyc macierzy";
	}
	return matrix;
}
void PrintMatrix(const std::vector<std::vector<int>>&matrix){
	int w1 = matrix.size();
	int l1 = matrix[0].size();
	for (int i = 0; i < w1; i++){
		for (int j = 0; j < l1; j++){
			std::cout << matrix[i][j] << std::endl;
			}
		}
}

int main()
{	
	PrintMatrix(MultiplyMatrix(CreateMatrix(), CreateMatrix()));

	return 0;
}