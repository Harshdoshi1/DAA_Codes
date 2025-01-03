#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    void findMinCoins(int denominations[], int n, int amount) {
        int coinCount = 0;
        int remainingAmount = amount;
        
        sort(denominations, denominations + n, greater<int>());
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            while (remainingAmount >= denominations[i]) {3
                remainingAmount -= denominations[i];
                count++;
            }
            coinCount += count;
            cout << "Number of " << denominations[i] << " rs coins: " << count << endl;
        }

        if (remainingAmount > 0) 
            cout << "Exact amount cannot be dispensed." << endl;
        else 
            cout << "Minimum coins needed: " << coinCount << endl;
    }

int main() {
    int n, amount;
    
    cout << "Enter number of denominations: ";
    cin >> n;

    int denominations[n];
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> denominations[i];
    }
    
    cout << "Enter the amount: ";
    cin >> amount;

    findMinCoins(denominations, n, amount);

    return 0;
}
