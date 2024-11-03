#include <iostream>
#include "../Task_3/funcs.h"

int main() {
    setlocale(LC_ALL, "Russian");
	std::cout << "������� 3. ������� ������������ �������. ��������� ������������ ��������� ������� ��������� �������\n";
	std::cout << "�������� ������� ����� ������������, ������ 453502\n\n";
    while (true) {
        std::cout << "������� 1 ��� ������� ���������, 0 ��� ����������:\n";
        int type = readIntegerInLine();
        if (type != 1 && type != 0) {
            std::cout << "������������ ����\n";
            continue;
        }
        if (type == 0) {
            break;
        }
        //������
        const int row = getMatrixRows();
        const int col = getMatrixCols();
        //������������ ������
        int** mtrx = initMatrix(row, col);
        //���������� ������ ��������� �� ������� ���������
        int total = 0;
        std::cout << "�������� �������:\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cout << mtrx[i][j] << '\t';
                if (i == j && !(mtrx[i][j] % 2)) {
                    total += 1;
                }
            }
            std::cout << '\n';
        }
        if (!total) {
            std::cout << "������� ��������� �������� ������� �� �������� ������ �����\n";
            matrixFreeMemory(mtrx, row);
            mtrx = nullptr;
            continue;
        }
        //��������� ��������� � ������� ������ �� ������� ���������
        int* even_numbers;
        int multiply;
        findEvenAndMultiply(total, row, col, mtrx, even_numbers, multiply);
        matrixFreeMemory(mtrx, row);
        mtrx = nullptr;
        printResult(total, even_numbers, multiply);
        delete[] even_numbers;
        even_numbers = nullptr;
    }
	return 0; 
}