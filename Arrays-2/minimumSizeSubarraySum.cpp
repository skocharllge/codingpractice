class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start = 0;
        int cumSum = 0;
        int maxLength = INT_MAX;
        
        for(int end = 0; end < nums.size(); end++)
        {
            
            cumSum += nums[end];
            while(cumSum >= target)
            {
                // cout << start <<" " << end << " " << end - start << " " <<cumSum << endl;
                 maxLength = min(maxLength, end - start);
                 cumSum -= nums[start];
                 start++;
            }
            
 
        }
        return maxLength == INT_MAX ? 0 : maxLength+1;
        
    }
};
