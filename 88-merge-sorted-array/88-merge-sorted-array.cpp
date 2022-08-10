class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       vector<int>::iterator ptr = nums1.begin();
        advance(ptr, m);
        auto it = find(ptr, nums1.end(), 0);

        if (it != nums1.end())
        {
            int index = it - nums1.begin();
            int j = 0;

            for (int i = index; i < nums1.size(); i++)
            {
                nums1[i] = nums2[j];
                j++;
            }
            sort(nums1.begin(), nums1.end());
        }
    }
};