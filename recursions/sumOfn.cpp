#include <iostream>
using namespace std;


int sumOfn(int n){
    if(n == 0) return 0;
    return n + sumOfn(n - 1);
}
int main(){

    cout << sumOfn(5);
    return 1;
}