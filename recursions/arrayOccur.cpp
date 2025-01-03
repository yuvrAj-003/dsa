#include <iostream>
using namespace std;


int first(int arr[], int i, int n,int k){
    if(i == n){
        return -1;
    }
    if(arr[i] == k){
        return i;
    }
    first(arr, i+1,n,k);
}


int last(int arr[], int n,int k){
    if(n == -1){
        return -1;
    }
    if(arr[n] == k){
        return n;
    }
    last(arr,n-1,k);
}
int main(){
    int n = 5;
    int arr[n] = {1,2,2,3,3};
    int element;
    cout << "Enter the element: ";
    cin >> element;
    cout << "first occurance of " << element << " is: " << first(arr,0,n-1,element) << endl;
    cout << "last occurance of " << element << " is: " << last(arr,n-1,element);

    return 0;

}