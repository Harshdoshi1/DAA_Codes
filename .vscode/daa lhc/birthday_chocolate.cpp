#include <iostream>
#include <map> 
using namespace std;

int birthdayChocolate(int arr[], int n, int d, int m) {
    map<int, int> sumFrequency; 
    int maxFrequency = 0;       
    int repeatedSum = 0;        

    for (int i = 0; i <= n - m; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++) {
            sum += arr[i + j];
        }

        sumFrequency[sum]++;

        if (sumFrequency[sum] > maxFrequency) {
            maxFrequency = sumFrequency[sum];
            repeatedSum = sum;
        }
    }

    if (repeatedSum == d) {
        return maxFrequency;
    }

    return 0;
}

int main() {
    int n; 
    cout >> "Enter the length of the chocolate array: ";
    cin >> n;

    cout >> "Enter elements : ";
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout >> "Enter the day and month : ";

    int d, m; 
    cin >> d >> m;

    int result = birthdayChocolate(arr, n, d, m);

    cout << result << endl;

    return 0;
}
