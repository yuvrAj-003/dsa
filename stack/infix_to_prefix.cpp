#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

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

string infix_to_prefix(string str)
{
    string s = str;
    reverse(s.begin(), s.end());
    string res = "";
    stack<char> st;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
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
                res += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string st = "(a-b/c)*(a/k-l)";

    string prefix = infix_to_prefix(st);

    cout << prefix << endl;
}
