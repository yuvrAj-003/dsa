#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0) {
        cout << "Array is empty, cannot delete element." << endl;
        return 1;
    }

    n--;

    cout << "Name: yuvraj singh , Roll No: 2210997282" << endl;
    cout << "Array after deletion at the end: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
