#include <iostream>
using namespace std;

int main() {
    const int capacity = 10;
    int arr[capacity] = {1, 2, 3, 4, 5};
    int n = 5;
    int element = 10; // Element to insert
    int position = 3; // Position to insert at (1-based index)

    if (n >= capacity) {
        cout << "Array is full, cannot insert element." << endl;
        return 1;
    }

    if (position < 1 || position > n + 1) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    for (int i = n; i >= position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    n++;

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Array after insertion at position " << position << ": ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
