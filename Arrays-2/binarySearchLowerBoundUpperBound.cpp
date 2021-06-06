class Solution {
public:
    
    int searchLowerEnd(vector<int>&nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
        int low = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
       
            if(nums[mid] == target)
            {
                low = mid;
                end = mid-1;
                
            }
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
        }
        
        return low;
    }
    
    int searchHigherEnd(vector<int>&nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
        int high = -1;
        
        while(start <=end)
        {
            int mid = start + (end - start)/2;
                         
            if(nums[mid] == target)
            {
                high = mid;
                start = mid+1;
                
            }
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
        }
        
        return high;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>answer;
        
        
       int lowIndex =  searchLowerEnd(nums, target);
        
       int highIndex = searchHigherEnd(nums, target);
        
       answer.push_back(lowIndex);
       answer.push_back(highIndex);
        
       return answer;
        
        
        
    }
};
