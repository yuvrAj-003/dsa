#include <iostream>
using namespace std;
#include <stack>

bool isValid(string s)
{
    stack<char> st;

    int n = s.length();
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    string s = "({[]})";

    if (isValid(s))
    {
        cout << "string is valid";
    }
    else
    {
        cout << "string is invalid";
    }
}