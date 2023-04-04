#include "modAlphaCipher.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для шифрования сообщения
string encryptMessage(string message, int numRows, int numCols) {
    // Разбиваем сообщение на блоки по numCols символов
    vector<string> blocks;
    for (int i = 0; i < message.length(); i += numCols) {
        blocks.push_back(message.substr(i, numCols));
    }

    // Дополняем последний блок пробелами, если необходимо
    if (blocks.back().length() < numCols) {
        blocks.back() += string(numCols - blocks.back().length(), ' ');
    }

    // Создаем таблицу для перестановки
    vector<vector<int>> table(numRows, vector<int>(numCols));
    int i = 0, j = 0, k = 1;
    while (j < numCols) {
        table[i][j] = k;
        k++;
        i++;
        if (i == numRows) {
            i = 0;
            j++;
        }
    }

    // Переставляем блоки в соответствии с таблицей
    string result;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int index = table[i][j] - 1; // Индекс блока в blocks
            if (index < blocks.size()) {
                result += blocks[index][j];
            }
        }
    }
    return result;
}

// Функция для дешифрования сообщения
string decryptMessage(string message, int numRows, int numCols) {
    // Разбиваем сообщение на блоки по numRows символов
    vector<string> blocks(numCols);
    int blockLength = numRows * ((message.length() + numRows - 1) / numRows);
    for (int i = 0; i < numCols; i++) {
        blocks[i] = message.substr(i * blockLength, blockLength);
    }

    // Создаем таблицу для перестановки
    vector<vector<int>> table(numRows, vector<int>(numCols));
    int i = 0, j = 0, k = 1;
    while (j < numCols) {
        table[i][j] = k;
        k++;
        i++;
        if (i == numRows) {
            i = 0;
            j++;
        }
    }

    // Переставляем блоки в соответствии с таблицей
    string result;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int index = table[i][j] - 1; // Индекс блока в blocks
            if (index < blocks.size()) {
                result += blocks[index][i];
            }
        }
    }

    // Удаляем пробелы из конца сообщения
    while (result.back() == ' ') {
        result.pop_back();
    }

    return result;
}
