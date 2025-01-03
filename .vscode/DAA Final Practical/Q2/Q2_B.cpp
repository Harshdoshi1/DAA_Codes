#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCuts(int n, int x, int y, int z) {
    vector<int> dp(n + 1, 0); 

    for (int i = 1; i <= n; i++) {
        // Check if we can make a cut of length 'x' at position 'i'
        
        if (i >= x && dp[i - x] != -1) 
            dp[i] = max(dp[i], dp[i - x] + 1); //here it means that dp[i - x] must not be -1 (it means we can form a valid segment of length i - x)

        if (i >= y && dp[i - y] != -1) 
            dp[i] = max(dp[i], dp[i - y] + 1); 

        if (i >= z && dp[i - z] != -1) 
            dp[i] = max(dp[i], dp[i - z] + 1); 
    }

    return dp[n];
}

int main() {
    int n, x, y, z;

    cout << "Enter the length of the line segment (n): ";
    cin >> n;
    cout << "Enter the cut lengths (x, y, z): ";
    cin >> x >> y >> z;

    cout << "Maximum number of segments: " << maxCuts(n, x, y, z) << endl;

    return 0;
}
