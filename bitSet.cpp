#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<95> bits;

    bits[0] = 1;   // set bit at index 0
    bits[94] = 1;  // set bit at index 94

    cout << bits << endl;
    return 0;
}
