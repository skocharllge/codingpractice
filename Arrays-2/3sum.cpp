class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;
        if(!nums.size() ) return answer;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            
            int start = i +1 ;
            int end = nums.size()-1;
            
             if (i != 0 && nums[i] == nums[i - 1]) continue;
            
            while(start < end)
            {
                int result = a+ nums[start] + nums[end];
                if(result == 0)
                {
                    //get into vector
                    vector<int> temp;
                    temp.push_back(a);
                    temp.push_back(nums[start]);
                    temp.push_back(nums[end]);
                    answer.push_back(temp);
                    start ++;
                    while (start < end && nums[start] == nums[start - 1]) ++start;          

                    
                }
                else if(result > 0)
                {
                    end--;
                }
                else if(result < 0)
                {
                    start ++;
                }
            }
        }
        return answer;
        
    }
};
