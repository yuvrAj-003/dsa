#include <iostream>
using namespace std;


void dec(int n){

    if(n == 0) return;

    cout << n << endl;
    dec(n - 1);
}

void asc(int n){

    if(n == 0) return;

    
    asc(n-1);
    cout << n << endl;
    
}

int main(){
    // dec(5);
    dec(5);
    cout << endl;
    asc(5);

    return 0;
}