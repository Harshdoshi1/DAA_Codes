#include <iostream>

using namespace std;

int main(){
    int A = 2;
    int B = 10;

    string bits[10] = {"0000", "0001", "0010", "0011", "0100"
                       "0101", "0110", "0111", "1000", "1001"};

    if (A==2 && B==10)
    {
        cout << "first bit need to flip" << endl;
    }
    
    cout << "A = 2" << endl;
    cout << bits[1] << endl;

    cout << "B = 8" << endl;
    cout << bits[9] << endl;
    
}