class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int partSum = accumulate(nums.begin(), nums.end(), 0);
        int sumPrev = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int sumAfter = 0;
            if (i == 0)
            {
                sumAfter += partSum - nums[i];
            }
            else
            {
                sumPrev += nums[i - 1];
                sumAfter += partSum - (sumPrev + nums[i]);
            }

            if (sumPrev == sumAfter)
            {
                return i;
            }
        }
        return -1;
    }
};