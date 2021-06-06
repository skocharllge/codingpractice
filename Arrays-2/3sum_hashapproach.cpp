//This solution gave TLE 316 \/ 318 test cases passed.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>answer;
        if(!nums.size() || nums.size() < 2)
        {
            return answer;
        }
        
        std::unordered_map<int, int>myMap;

	//insert into hashmap for 2sum type look up
        
        for(int i=0; i< nums.size(); i++)
        {
            myMap[nums[i]] = i;
        }
       
	//We will have triplets , so vector<int> gives the triplet . We will have duplicate triplets .So we sort the vector and insert into set . The set does not allow duplicate triplets
        set<vector<int>> mySet;
        for(int i =0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
             
                int k = 0-nums[i]-nums[j];
                
                auto itr = myMap.find(k);
                if(itr != myMap.end())
                {
                    if(i != j && itr->second != i && itr->second != j)
                    {
                         vector<int>temp;
                         temp.push_back(nums[i]);
                         temp.push_back(nums[j]);
                         temp.push_back(itr->first);
                        
                         sort(temp.begin(), temp.end());
 
                         if(mySet.find(temp)== mySet.end())
                         mySet.insert(temp);
                        
                
                    }
                }
                
            }
        }
     
	//This last snippet is to copy from set to vector
       
        for(auto elem: mySet)
        {
            std::vector<int>temp(elem.size());
            
            std::copy(elem.begin(), elem.end(), temp.begin());
            
            answer.push_back(temp);
        
        }
       
        return answer;
    }
    
};
