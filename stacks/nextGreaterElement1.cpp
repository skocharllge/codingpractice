//First decide it is stack problem and then start thinking about monotonic and then about
//decreasing or increasing 

//This problem uses monotonic decreasing stack

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
             
        unordered_map<int, int>myMap;
        stack<vector<int>>myStack;
      
        
        for(int i = nums2.size()-1; i >=0; i--)
        {
            //Lets build monotonic decreasing stack 
            int valDefault = -1;
            while(!myStack.empty())
            {
                auto element = myStack.top();
                
                if(element[0] <= nums2[i])
                {
                    myStack.pop();
    
                }
                else
                {
                    valDefault = element[0];
                    break;
                }
               
            }
 
            myStack.push({nums2[i], valDefault});
            myMap[nums2[i]] = valDefault;
        }
        
        vector<int>answer;
        for(auto element: nums1)
        {
            answer.push_back(myMap[element]);
        }
        
        return answer;
        
    }
};
