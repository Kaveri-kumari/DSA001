class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currentMax = nums[0];
        int currentMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int x = nums[i];

            int v1 = x;
            int v2 = currentMax * x;
            int v3 = currentMin * x;

            int newMax = max(v1, max(v2, v3));
            int newMin = min(v1, min(v2, v3));

            currentMax = newMax;
            currentMin = newMin;

            ans = max(ans, currentMax);
        }

        return ans;
    }
};