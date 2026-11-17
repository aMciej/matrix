#include <iostream>
#include <vector>
#include "Matrix.h"

    void Matrix::setData(std::vector<std::vector<int>> data){
        Data = data;
    }
	void Matrix::setRows(int rows){
		Rows = rows;
	}
	void Matrix::setColumns(int columns){
		Columns = columns;
	}
	int const Matrix::getRows (){
		return Rows;
	}
	int const Matrix::getColumns (){
		return Columns;
	}
    std::vector<std::vector<int>> Matrix::getData(){
        return Data;
    }
	Matrix::Matrix(std::vector<std::vector<int>> data, int rows, int columns){
        Data = data;
		Rows = rows;
		Columns = columns;
	}

    void Matrix::read(){
        Data.resize(getRows(), std::vector<int>(getColumns()));
	for (int i = 0; i < getRows(); i++){
		for(int j = 0; j< getColumns(); j++){
			std::cout << "Podaj liczbe:";
			std::cin >> Data[i][j];
			}
		}
    }
	
	void Matrix::add(const Matrix& m){
		std::vector<std::vector<int>>output(Rows, std::vector<int>(m.Columns,0));
	if (Rows == m.Rows and Columns == m.Columns){
		for (int i = 0; i < Rows; i++){
			for (int j = 0; j < Columns; j++){
				output[i][j] = Data[i][j] + m.Data[i][j];
			}
		}
	}else{
		std::cout << "Nie mozna dodac macierzy";
		}
	}

	void Matrix::multiply(const Matrix& m){
		std::vector<std::vector<int>>output(Rows, std::vector<int>(m.Columns,0));
	if (Columns == m.Rows){
		for (int i = 0; i < Columns; i++){
			for (int j = 0; j < m.Columns; j++){
				for(int k = 0; k < Columns; k++){
				output[i][j] += Data[i][k] * m.Data[k][j];
				}
			}
		}
		Data = output;
		Columns = m.Columns;
	}else{
		std::cout << "Nie mozna pomnozyc macierzy";
		}
	}

	void Matrix::print(){
		Data.resize(getRows(), std::vector<int>(getColumns()));
	for (int i = 0; i < getRows(); i++){
		for(int j = 0; j< getColumns(); j++){
			std::cout << Data[i][j] << " ";
			}
		}
	}