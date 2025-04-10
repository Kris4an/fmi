#include <iostream>

const int MAX_ROWS = 32;
const int MAX_COLS = 32;

int zad1(int matrix[][MAX_COLS], int rows, int cols)
{
    int s = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            s += matrix[i][j];
        }
    }
    return s;
}
void zad2(int matrix[][MAX_COLS], int n)
{
    char secondDiagonal[n + 1], mainDiagonal[n + 1];
    char under1[n * (n + 1) / 2], under2[n * n];

    for (int i = 0, k = 0, s = 0; i < n; ++i)
    {
        mainDiagonal[i] = matrix[i][i] + '0';
        secondDiagonal[i] = matrix[n - 1 - i][n - 1 - i] + '0';

        for (int j = 0; j < i; ++j, ++k, ++s)
        {
            under1[k] = matrix[i][j] + '0';
            if (s < n * (n - 1))
                under2[s] = ' ';
        }

        for (int j = i + 1; j < n; ++j, ++s)
        {
            under2[s] = matrix[i][j] + '0';
        }

        under1[k] = '\n';
        ++k;
        under2[s] = '\n';
        ++s;
    }
    std::cout << mainDiagonal << '\n'
              << secondDiagonal << under1 << '\n'
              << under2;
}
void zad3(bool operation, int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2){
    if(rows1 != rows2 || cols1 != cols2){
        std::cout<<"KYS";
        return;
    }
    for(int i = 0; i < rows1; ++i){
        for(int j = 0; j < cols1; ++j){
            if(operation) std::cout<<(matrix1[i][j]+matrix2[i][j])<<' ';
            else std::cout<<(matrix1[i][j]-matrix2[i][j])<<' ';
        }
        std::cout<<std::endl;
    }
}
void zad5(int** matrix, int rows, int cols){
    for(int i = 0; i < cols; ++i){
        for(int j = 0; j < rows; ++j){
            if(i%2==0)std::cout<<matrix[i][j];
            else std::cout<<matrix[j][cols-i];
        }
    }
}
int main()
{
    int rows = 3, cols = 3;
    int arr[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}};
        int** matrix = new int*[rows];
    for(int i = 0; i < rows; ++i){
        matrix[i] = new int[cols];
        for(int j = 0; j < cols; ++j){
            matrix[i][j] = j+1;
        }
    }
    // std::cout<<(zad1(arr, rows, cols));
    //zad2(arr, rows < cols ? rows : cols);
    //zad3(0, arr, rows, cols, arr, rows, cols);
    zad5(matrix, rows, cols);
    return 0;
}