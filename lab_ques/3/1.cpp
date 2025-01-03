#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 3; // Element to search

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Searching for element " << element << " using Linear Search..." << endl;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == element) {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found." << endl;
    }

    return 0;
}
