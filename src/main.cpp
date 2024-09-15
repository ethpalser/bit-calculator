#include <iostream>
using namespace std;

void println(char (&output)[]) {
    std::cout << output << '\n';
}

int bitArrayToInt32(bool bits[32]) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        if (bits[i]) {
            res |= 1 << i;
        }
    }
    return res;
}

bool nthBit(int num, int n) {
    return num >> n & 1;
}

int bitAdd(int a, int b) {
    bool bits[32];
    bool carry = 0;
    bool aBit, bBit;
    for (int i = 0; i < 32; i++) {
        aBit = nthBit(a, i);
        bBit = nthBit(b, i);
        bits[i] = aBit ^ bBit ^ carry;
        carry = (aBit & bBit) | (aBit & carry) | (bBit & carry);
    }
    return bitArrayToInt32(bits);
}

int bitSubtract(int a, int b) {
    bool bits[32];
    bool carry = 0;
    // Get the 2scompliment of b then add 1 for 1sCompliment
    int bComp = bitAdd(~b, 1);
    
    bool aBit, bBit;
    for (int i = 0; i < 32; i++) {
        aBit = nthBit(a, i);
        bBit = nthBit(bComp, i);
        bits[i] = aBit ^ bBit ^ carry;
        carry = (aBit & bBit) | (aBit & carry) | (bBit & carry);
    }
    return bitArrayToInt32(bits);
}

int main() {
    std::cout << "5 + 1 = " << std::to_string(bitAdd(5, 1)) << "\n";
    std::cout << "5 + 7 = " << std::to_string(bitAdd(5, 7)) << "\n";
    std::cout << "5 + -7 = " << std::to_string(bitAdd(5, -7)) << "\n";
    std::cout << "5 - 1 = " << std::to_string(bitSubtract(5, 1)) << '\n';
    std::cout << "5 - 7 = " << std::to_string(bitSubtract(5, 7)) << "\n";
    std::cout << "5 - -7 = " << std::to_string(bitSubtract(5, -7)) << "\n";
    std::cout << "max int + 1 = " << std::to_string(bitAdd(2147483647, 1)) << "\n";
    std::cout << "min int - 1 = " << std::to_string(bitSubtract(-2147483648, 1)) << "\n";
    return 0;
}