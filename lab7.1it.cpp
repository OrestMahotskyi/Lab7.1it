#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Функція для генерації матриці випадкових чисел у заданому діапазоні
void CreateMatrix(int** matrix, const int rows, const int cols, const int low, const int high) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = low + rand() % (high - low + 1);
}

// Функція для виведення матриці у вигляді таблиці
void PrintMatrix(int** matrix, const int rows, const int cols) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для обчислення кількості та суми елементів за критерієм, а також заміни їх нулями
void CalculateAndReplace(int** matrix, const int rows, const int cols, int& sum, int& count) {
    sum = 0;
    count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Критерій: непарні або невід’ємні
            if ((matrix[i][j] % 2 != 0) || (matrix[i][j] >= 0)) {
                sum += matrix[i][j];
                count++;
                matrix[i][j] = 0;
            }
        }
    }
}

// Функція для сортування рядків матриці за заданими ключами
void SortMatrix(int** matrix, const int rows, const int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if ((matrix[j][0] > matrix[j + 1][0]) ||
                (matrix[j][0] == matrix[j + 1][0] && matrix[j][1] > matrix[j + 1][1]) ||
                (matrix[j][0] == matrix[j + 1][0] && matrix[j][1] == matrix[j + 1][1] && matrix[j][3] < matrix[j + 1][3])) {
                // Обмін рядків місцями
                for (int k = 0; k < cols; k++) {
                    int temp = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = temp;
                }
            }
        }
    }
}

int main() {
    srand(time(0));

    const int rows = 7;
    const int cols = 6;
    const int low = -12;
    const int high = 23;
    
    // Створення матриці
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    CreateMatrix(matrix, rows, cols, low, high);
    cout << "Original Matrix:";
    PrintMatrix(matrix, rows, cols);

    // Виконання обчислень
    int sum = 0, count = 0;
    CalculateAndReplace(matrix, rows, cols, sum, count);
    cout << "Modified Matrix after Calculation:";
    PrintMatrix(matrix, rows, cols);
    cout << "Sum of elements = " << sum << endl;
    cout << "Count of elements = " << count << endl;

    // Сортування матриці
    SortMatrix(matrix, rows, cols);
    cout << "Sorted Matrix:";
    PrintMatrix(matrix, rows, cols);

    // Видалення матриці з пам'яті
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
