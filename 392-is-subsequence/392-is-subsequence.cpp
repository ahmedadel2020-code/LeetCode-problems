class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> vt;
        if (s.empty())
        {
            return true;
        }
        int pos = 0;
        if (s[0] == t[0])
        {
            vt.push_back(0);
        }
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = pos + 1; j < t.length(); j++)
            {
                if (s[i] == t[j])
                {
                    pos = j;
                    vt.push_back(pos);
                    break;
                }
            }
        }
        if (!vt.empty())
        {
            int curr = vt[0];
            for (int i = 0; i < vt.size(); i++)
            {
                if (vt[i] < curr)
                {
                    return false;
                }
                else
                {
                    curr = vt[i];
                }
            }
        }
        if (vt.size() < s.size())
        {
            return false;
        }


        return true;
    }
};