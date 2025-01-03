#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int position = 3; // Position to delete (1-based index)

    if (n == 0) {
        cout << "Array is empty, cannot delete element." << endl;
        return 1;
    }

    if (position < 1 || position > n) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    for (int i = position - 1; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    n--;

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Array after deletion at position " << position << ": ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
