// - + 7 * 4 5 + 2 0
#include <iostream>
using namespace std;
#include <stack>

int prefix_eval(string s)
{
    stack<int> st;
    int n = s.length();

    // int result = 0;

    for (int i = n - 1; i >= 0; i--)
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
    string prefix = "-+7*45+20";

    int ans = prefix_eval(prefix);

    cout << ans;
}