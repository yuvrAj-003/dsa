#include <iostream>
using namespace std;
#include <stack>

int pres(char c)
{

    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    string s = "(a-b/c)*(a/k-l)";

    int n = s.length();

    string temp = "";
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            temp += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                temp += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            if (!st.empty() && pres(st.top()) > pres(s[i]))
            {
                temp += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        temp += st.top();
        st.pop();
    }

    cout << temp << endl;

    return 0;
}
