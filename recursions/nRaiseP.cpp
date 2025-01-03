#include <iostream>
using namespace std;


int nRaiseP(int n,int p){
    if(p == 0) return 1;
    return n *  nRaiseP(n,p-1);
}
int main(){

    cout << nRaiseP(5,5);
    return 1;
}