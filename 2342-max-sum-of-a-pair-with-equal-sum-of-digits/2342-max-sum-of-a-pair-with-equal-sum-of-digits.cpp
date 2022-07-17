class Solution {
public:
    int countDigit(int n)
    {
        int m;
        if (n == 0)
            return n;
        int sum = 0;
        while (n != 0)
        {
            m = n % 10;
            sum += m;
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> unmap;
        int res = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = countDigit(nums[i]);
            if (unmap.find(sum) != unmap.end())
            {
                res = max(res, unmap[sum] + nums[i]);
            }
            unmap[sum] = max(unmap[sum], nums[i]);
        }    
        return res;
    }
};