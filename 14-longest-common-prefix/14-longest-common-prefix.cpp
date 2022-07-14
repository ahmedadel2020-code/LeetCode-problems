class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string newStr = "";
    int size = strs.size();
    if (size == 0)
    {
        return "";
    }
    sort(begin(strs), end(strs));
    string firstString = strs[0];
    string lastString = strs[size - 1];
    for (int i = 0; i < firstString.size(); i++)
    {
        if (firstString[i] == lastString[i])
        {
            newStr.push_back(firstString[i]);
        }
        else
        {
            break;
        }
    }
    return newStr;
    }
};