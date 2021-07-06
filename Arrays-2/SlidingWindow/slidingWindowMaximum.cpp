
class Solution {

public:

   multiset<int>pq;
    vector<int>answer;
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
       int start = 0;
        
       for(int end = 0; end < nums.size(); end++)
       {
           pq.insert(nums[end]);
           
           if(end >= k - 1 )
           {
                                                     
               auto itr = pq.rbegin();
               int element = *itr;
               answer.push_back(element);
               
               if(!pq.empty())
               {
                     //with pq erase if we do not use lower_bound, it will remove all the elements which are 
                    // equal to the element .
                     pq.erase(pq.lower_bound(nums[start]));
                     
               }
               start ++;
           }
           
       }
    
       return answer;
        
    }
};
