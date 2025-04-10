#include <iostream>
#include <fstream>

int main() {
    const int size = 5;
    int numbers[size] = {10, 20, 30, 40, 50};  // Масив от числа за запис
    int readNumbers[size];                    // Масив за четене от файл

    // 1. Записване на масива в двоичен файл
    std::ofstream outFile("binary_data.bin", std::ios::binary | std::ios::out); // Отваряне в двоичен режим
    if (!outFile) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    // Записване на целия масив
    outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));

    // Проверка за успешно записване
    if (!outFile) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    outFile.close();

    // 2. Четене на масива от двоичния файл
    std::ifstream inFile("binary_data.bin", std::ios::binary | std::ios::in); // Отваряне в двоичен режим
    if (!inFile) {
        std::cerr << "Cannot open file!" << std::endl;
        return 1;
    }

    // Четене на целия масив
    inFile.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers));

    // Проверка за успешно четене
    if (!inFile) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    inFile.close();

    // 3. Извеждане на прочетените данни
    std::cout << "Data: ";
    for (int i = 0; i < size; ++i) {
        std::cout << readNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
