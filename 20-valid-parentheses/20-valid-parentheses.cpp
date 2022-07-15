class Solution {
public:
    bool isValid(string s) {
            stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (!st.empty())
            {
                char t = st.top();

                if (t == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty())
            {
                char t = st.top();
                if (t == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }

        }
        else if (s[i] == ']')
        {
            if (!st.empty())
            {
                char t = st.top();
                if (t == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
           
        }
        else
        {
            st.push(s[i]);
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
    }
};