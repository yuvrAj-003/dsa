#include <iostream>
using namespace std;

int main() {
    const int capacity = 10;
    int arr[capacity] = {1, 2, 3, 4, 5};
    int n = 5;
    int element = 10; // Element to insert at the beginning

    if (n >= capacity) {
        cout << "Array is full, cannot insert element." << endl;
        return 1;
    }

    for (int i = n; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    n++;

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Array after insertion at the beginning: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
