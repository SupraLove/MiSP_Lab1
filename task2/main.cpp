#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;
bool isValid(const wstring& s)
{
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    int klych=2;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring z;
    wstring text;
    unsigned op;
    Cipher cipher(klych);
    do {
        wcout<<L"ВЫБЕРИТЕ ОПЕРЦИЮ(0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (isValid(text)) {
            if (op >0) {
            wcout<<L"ВВЕДЕИТЕ ТЕКСТ СОСТОЯЩИЙ ИЗ ЛИТИНИЦЫ: ";
            wcin>>text;
                if (op==1) {
                    wcout<<L"ЗАШИФРОВАННАЯ СТРОКА: "<<cipher.zakodirovatCipher(cipher, text)<<endl;
                } else {
                    wcout<<L"РАСШИФРОВАННАЯ СТРОКА: "<<cipher.raskodirovatCipher(cipher, text)<<endl;
                }
                }
        }
    } while (op!=0);
    return 0;
}
