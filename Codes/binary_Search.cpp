#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = binarySearch(arr, 0, arr.size() - 1, x);

    if (result == -1) {
        std::cout << "Element not found\n";
    } else {
        std::cout << "Element found at index " << result << '\n';
    }
    return 0;
}
