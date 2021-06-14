class Solution {
public:
    
    stack<vector<int>>leftStack; //Traverse left to right for increasing monotonic stack 
    //Numbers increase from bottom to top which is increasing monotonic stack
    stack<vector<int>>rightStack;
    vector<int>leftTraversal;
    vector<int>rightTraversal;
    
    int largestRectangleArea(vector<int>& heights) {
        
 	//Get the left max index using increasing monotonic stack      
        for(auto element:heights)
        {
            int defaultValue = 1;
            vector<int>topElement;
            while(!leftStack.empty())
            {
                topElement = leftStack.top();
                
                if(topElement[0] >= element)
                {
                    leftStack.pop();
                    defaultValue += topElement[1];
                }
                else
                {
                    break;
                }
            }
            leftStack.push({element, defaultValue});
            leftTraversal.push_back(defaultValue);
            
        }
   
        //Get the right max index using increasing monotonic stack  
       
        for(int i = heights.size()-1; i >=0; i--)
        {
            int defaultValue = 1;
            vector<int>topElement;
            while(!rightStack.empty())
            {
                topElement = rightStack.top();
                
                if(topElement[0] >= heights[i])
                {
                    rightStack.pop();
                    defaultValue += topElement[1];
                }
                else
                {
                    break;
                }
            }
            rightStack.push({heights[i], defaultValue});
            rightTraversal.push_back(defaultValue);
        }
       
	//push_back from right end of vector , so reverse needed ..Look for additional time complexity
        reverse(rightTraversal.begin(), rightTraversal.end());
        
        //Now calculate the area and get the max  
        
        int maxArea = INT_MIN;
        
        for(int i = 0; i < heights.size(); i++)
        {
	   //-1 needed because we might just width twice from both left end and right end 
            maxArea = max(maxArea, heights[i] * ( leftTraversal[i]  +  rightTraversal[i] -1));
        }
        
        return maxArea;
    }
};
