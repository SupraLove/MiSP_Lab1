#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RouteCipher {
private:
    int rows;
    int cols;
    vector<vector<char>> grid;

public:
    RouteCipher(int r, int c) : rows(r), cols(c) {
        grid.resize(r, vector<char>(c, ' '));
    }

    void encrypt(string plaintext) {
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (index >= plaintext.length())
                    break;
                grid[i][j] = plaintext[index];
                index++;
            }
        }
    }

    void printGrid() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    string decrypt() {
        string ciphertext;
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                ciphertext += grid[i][j];
            }
        }
        return ciphertext;
    }
};

int main() {
    RouteCipher rc(3, 5);
    rc.encrypt("HELLOWORLD");
    rc.printGrid();
    cout << rc.decrypt() << endl;

    return 0;
}
