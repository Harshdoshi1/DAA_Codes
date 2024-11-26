#include <iostream>
using namespace std;

int main() {
    int A[10] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int B[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int len = 0, l = 0;

    for (int i = 0; i < 10; i++) {
        if (A[i] == B[i]) {
            len++;
        } else {
            if (l < len) {
                l = len;
            }
            len = 0;
        }
    }

    if (l != 0)
        cout << l;
    else
        cout << "no match";

    return 0;
}
