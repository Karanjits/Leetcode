#include <iostream>
#include <string>

using namespace std;


int main () {
  
    string test = "HELLO WORLD";

   const char* chars =test.c_str();

    for(int i=0; i<12;i++) {

        cout << chars[i] <<endl;

    }
    

    return 0;

}