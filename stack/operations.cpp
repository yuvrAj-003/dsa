#include <iostream>
using namespace std;
#define n 100

class stack {

    int* arr;
    int top;

    public:
    
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top == n-1){
            cout << "OVERFLOW";
            return;
        }
        top++;
        arr[top] = x;
        cout << "PUSH: " << x << " is added" << endl;

    }

    void pop(){
        if(top == -1){
            cout << "UNDERFLOW";
            return;
        }
        int elm = arr[top];
        arr[top] = 0;
        top--;

        cout << "POP: " << elm << " is removed" << endl;
        
    }
    int peek(){

        if(top == -1){
            cout << "no element present";
            return -1;
        }
        return arr[top];


    }

    bool empty(){
        return top==-1;
    }
};


int main(){
    stack st;
    
    while(true){
        cout << "STACK\n1. push\n2. pop\n3. top\n4. check empty\n5. Any other key to exit\nEnter your option: ";
        int op;
        cin >> op;

        switch(op){
            case 1:
                int val;
                cout << "Enter the value to push: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                if(!st.empty()){
                    cout << "Top element: " << st.peek() << endl;
                }
                break;
            case 4:
                if(st.empty()){
                    cout << "stack is empty" << endl;
                }
                else{
                    cout << "stack is not empty" << endl;
                }
                break;
            default:
                exit(0);
        }
        cout << endl;
        
    }

    return 0;
}