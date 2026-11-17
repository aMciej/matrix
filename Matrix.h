#include <iostream>
#include <vector>

class Matrix{
    private:

	std::vector<std::vector<int>> Data;
	int Rows;
	int Columns;

    public:

    void setRows(int rows);
    void setColumns(int columns);
    void setData(std::vector<std::vector<int>> data);
    int const getRows();
    int const getColumns();
    std::vector<std::vector<int>> getData();
    Matrix(std::vector<std::vector<int>> data, int rows, int columns);
    void read();
    void add(const Matrix&);
    void multiply(const Matrix&);
    void print();
};