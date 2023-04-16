#include "modAlphaCipher.h"
Cipher::Cipher(int password)
{
    this->p=password;
}
wstring Cipher::zakodirovatCipher(Cipher w, wstring& s)
{
    wstring Output;
    int v;
    int dlina = s.size();
    if (s.size() % w.p != 0) {
        v = s.size() / w.p + 1;
    } else {
        v = s.size() / w.p;
    }
    wchar_t x[v][w.p];
    int p = 0;
    for (int i = 0; i < v; ++i) {
        for (int k = 0; k < w.p; ++k) {
            if (p < s.length()) {
                x[i][k] = s[p];
                ++p;
            } else x[i][k] = ' ';
        }
    }
    for (int i = w.p - 1; i >= 0; --i) { // изменяем направление обхода
        for (int k = 0; k < v; ++k) {
            Output += x[k][i]; // добавляем символ в выходную строку
        }
    }
    return Output;
}

wstring Cipher::raskodirovatCipher(Cipher w, wstring& s)
{
    wstring Output;
    int v;
    int dlina = s.size();
    if (s.size() % w.p != 0) {
        v = s.size() / w.p + 1;
    } else {
        v = s.size() / w.p;
    }
    wchar_t x[v][w.p];
    int p = 0;
    for (int i = w.p - 1; i >= 0; --i) {
        for (int k = 0; k < v; ++k) {
            x[k][i] = s[p]; // записываем символ в текущую ячейку
            ++p;
        }
    }
    for (int i = 0; i < v; ++i) {
        for (int k = 0; k < w.p; ++k) {
            Output += x[i][k]; // добавляем символ в выходную строку
        }
    }
    return Output;
}
