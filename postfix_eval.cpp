#include <iostream>
#include <stack>
using namespace std;

int postfix_evaluation(string s)
{
    stack<int> st;
    int n = s.length();
    // int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int o1 = st.top();
            st.pop();
            int o2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(o1 + o2);

                break;
            case '-':
                st.push(o1 - o2);
                break;
            case '*':
                st.push(o1 * o2);
                break;
            case '/':
                st.push(o1 / o2);
                break;
            default:
                return -1;
            }
        }
    }
    if (st.empty())
    {
        return -1;
    }

    return st.top();
}
int main()
{
    string postfix = "123/-47/6-*";
    cout << "Postfix expression evaluation: " << postfix_evaluation(postfix);

    return 0;
}
