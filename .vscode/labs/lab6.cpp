// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <ctime>
// #include <chrono>
// #include <cmath>
// #include <utility>

// int main() {
//     int w = 40; // Maximum weight the knapsack can carry
//     std::vector<int> val = {60, 100, 120, 150}; // Values of the items
//     std::vector<double> wt = {10.0, 20.0, 20.0, 40}; // Weights of the items
//     int n = val.size(); // Number of items

//     // Vector to store value-to-weight ratio and item index
//     std::vector<std::pair<double, int>> daabo;
//     for (int i = 0; i < n; i++) {
//         // Calculate value-to-weight ratio and store it with item index
//         daabo.push_back(std::make_pair(val[i] / wt[i], i));
//     }

//     // Sort the items based on value-to-weight ratio in descending order
//     std::sort(daabo.begin(), daabo.end(), std::greater<std::pair<double, int>>());

//     double ans = 0; // Variable to store the final result (total value)
    
//     for (int i = 0; i < n; i++) { // Loop over the sorted items
//         // If the item can fit in the knapsack
//         if (wt[daabo[i].second] <= w) {
//             // Add the entire value of the item
//             ans += val[daabo[i].second];
//             w -= wt[daabo[i].second]; // Decrease the remaining weight
//         } else {
//             // If the item can't fit fully, take the fraction of it
//             ans += (val[daabo[i].second] * w) / wt[daabo[i].second];
//             break; // Knapsack is full, no need to check further
//         }
//     }

//     std::cout << "Maximum value in the knapsack: " << ans << std::endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <cmath>
#include <utility>

int main() {
    int w = 40; // Knapsack capacity
    std::vector<int> val = {60, 100, 120, 150}; // Values of items
    std::vector<double> wt = {10.0, 20.0, 20.0, 40}; // Weights of items
    int n = val.size(); // Number of items
    
    // Vector to store value-to-weight ratio and the corresponding index
    std::vector<std::pair<double, int>> daabo;
    
    // Calculate value-to-weight ratio and store the ratio with the item's index
    for (int i = 0; i < n; i++) {
        daabo.push_back(std::make_pair((double)(val[i] / wt[i]), i));
    }

    // Sort the items based on value-to-weight ratio in descending order
    std::sort(daabo.begin(), daabo.end(), std::greater<std::pair<double, int>>());

    double ans = 0; // Variable to store the maximum value
    for (int i = 0; i < n; i++) { // Iterate through the sorted items
        if (wt[daabo[i].second] <= w) { // If the item can fit in the knapsack
            ans += val[daabo[i].second]; // Add its full value
            w -= wt[daabo[i].second]; // Decrease the remaining weight
        } else { // If the item can't fully fit, take the fractional part
            ans += (double)val[daabo[i].second] * w / wt[daabo[i].second];
            break; // Knapsack is full
        }
    }

    // Output the result
    std::cout << "Maximum value in the knapsack: " << ans << std::endl;

    return 0;
}
