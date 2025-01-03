#include <iostream>
using namespace std;


bool checkSorted(int *arr,int n){

    if(n == 1) return true;

    bool check = checkSorted(arr + 1, n-1);

    return (arr[0] < arr[1] && check);



}
int main(){
    int arr[5] = {1,2,6,4,5};

    cout << checkSorted(arr, 5);

    return 0;
}