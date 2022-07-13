class Solution {
public:
    int romanToInt(string s) {
                    int sum = 0;
    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;
    bool flag = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I' && s[i + 1] != 'V' && s[i + 1] != 'X')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += I;
        }
        else if (s[i] == 'V')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += V;
        }
        else if (s[i] == 'X' && s[i + 1] != 'L' && s[i + 1] != 'C')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += X;
        }
        else if (s[i] == 'L')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += L;
        }
        else if (s[i] == 'C' && s[i + 1] != 'D' && s[i + 1] != 'M')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += C;
        }
        else if (s[i] == 'D')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += D;
        }
        else if (s[i] == 'M')
        {
            if (flag)
            {
                flag = false;
                continue;
            }
            sum += M;
        }
        else if (s[i] == 'I' && s[i + 1] == 'V')
        {
            flag = true;
            sum += 4;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            flag = true;
            sum += 9;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            flag = true;
            sum += 40;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            flag = true;
            sum += 90;
        }
        else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            flag = true;
            sum += 400;
        }
        else if (s[i] == 'C' && s[i + 1] == 'M')
        {
            flag = true;
            sum += 900;
        }
    }
    return sum;
    }
};