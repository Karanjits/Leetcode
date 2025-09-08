#include <iostream>
using namespace std;




int main() {
    int weight;
    cout<<"Enter Weight: "<<endl;
    cin >> weight;

    if(weight %2 == 0) {
        cout<<"Yes";
    }else{cout<<"No";
    }
    return 0;
}