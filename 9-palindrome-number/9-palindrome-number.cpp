class Solution {
public:
    bool isPalindrome(int x) {
       	vector<char> vt;
	string str = to_string(x);
	bool flag = false;
	int l = 0;
	int r = str.length() - 1;
	for (int i = 0; i < str.length(); i++)
	{
		vt.push_back(str[i]);
	}
	if (vt.size() == 1)
	{
		return true;
	}
	while (l < r)
	{
		if (vt[l] == vt[r])
		{
			l++;
			r--;
			flag = true;
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		return true;
	}
	else
	{
		return false;
	}
    }
};