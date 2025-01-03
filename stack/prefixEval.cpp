#include <iostream>
#include <stack>
#include <math.h>
using namespace std;


int calcPrefix(string eq){
    stack<int> st;
    for(int i = eq.length() -1; i >= 0; i--){

        if(eq[i] >= '0' && eq[i] <= '9'){
            st.push(eq[i] - '0');
        }
        else{
            
            if(!st.empty()){

                int n1 = st.top();
                st.pop();
                int n2= st.top();
                st.pop();

                switch(eq[i]){
                    case '+':
                        st.push(n1+n2);
                        break;
                    case '-':
                        st.push(n1-n2);
                        break;
                    case '*':
                        st.push(n1*n2);
                        break;
                    case '/':
                        st.push(n1/n2);
                        break;
                    case '^':
                        st.push(pow(n1,n2));
                        break;
                    default:
                        cout << "Invalid prefix";
                        exit(0);
                }
            }  
            else{
                cout << "Invalid prefix";
                exit(0);
            }
        }
    }
    int elm = st.top();
    if(st.size() == 1){
        return elm;
    }
    else{
        cout << "Invalid prefix";
        exit(0);
    }
}



int main(){
    string prefix;
    cout << "Enter equation in prefix form: ";
    getline(cin, prefix);
    cout << "Prefix: " << prefix << endl;
    cout << "Ans: " << calcPrefix(prefix) << endl;
    return 0;
    

}