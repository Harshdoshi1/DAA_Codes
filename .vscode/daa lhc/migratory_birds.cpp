#include <iostream>
#include <set>
using namespace std;

void findRepeatingElements(int arr[], int n) {
    set<int> seen;        
    set<int> repeated;    

    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            repeated.insert(arr[i]);
        } else {
            seen.insert(arr[i]);
        }
    }

    if (!repeated.empty()) {
        cout << "The repeating elements are: ";
        for (int elem : repeated) {
            cout << elem << " ";
        }
        cout << endl;
    } else {
        cout << "No repeating elements found." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int* arr = new int[n];
    cout << "Enter the elements of the array (1-5): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (arr[i] < 1 || arr[i] > 5) {
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin >> arr[i];
        }
    }

    findRepeatingElements(arr, n);

    delete[] arr; 
    return 0;
}
