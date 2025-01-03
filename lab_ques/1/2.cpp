#include <iostream>
using namespace std;

int main() {
    const int capacity = 10;
    int arr[capacity] = {1, 2, 3, 4, 5};
    int n = 5;
    int element = 10; // Element to insert at the end

    if (n >= capacity) {
        cout << "Array is full, cannot insert element." << endl;
        return 1;
    }

    arr[n] = element;
    n++;

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Array after insertion at the end: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
