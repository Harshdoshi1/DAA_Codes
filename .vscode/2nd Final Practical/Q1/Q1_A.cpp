#include <iostream>
using namespace std;

int main() {
    string Dictionary[5] = {"apple", "application", "grape", "pineapple", "banana"};
    string Word[1] = {"apele"};

        cout << "Word : " << Word[0] << endl;

        if (Dictionary[1] == Word[1]) {
            cout << "OUTPUT : " << Dictionary[0];
        } 
        else 
        {
            cout << "Correct OUTPUT : " << Dictionary[0];
        }

}
