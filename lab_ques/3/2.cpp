#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 3; // Element to search

    int low = 0, high = n - 1, mid;

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Searching for element " << element << " using Binary Search..." << endl;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element) {
            cout << "Element found at position " << mid + 1 << endl;
            return 0;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element not found." << endl;

    return 0;
}
