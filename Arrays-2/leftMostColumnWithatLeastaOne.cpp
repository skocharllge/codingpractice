/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
//added leetcode url
class Solution {
public:
    
    int binarySearch(BinaryMatrix& binaryMatrix, int start, int end,int row)
    {
        
        //get the first one from each row 
        int lowIndex = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(binaryMatrix.get(row, mid) == 1)
            {
                end = mid -1;
                
                lowIndex = mid;
                
            }
            else 
            {
                start = mid+1;
            }
            
        }
        return lowIndex;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int>dimensions  = binaryMatrix.dimensions();
        
        int M = dimensions[0];
        
        int N = dimensions[1]-1;
        
        int lowIndex  = INT_MAX;
        int result = 0;
        
        
        for(int  i =0; i < M; i++)
        {
            result =  binarySearch(binaryMatrix, 0, N, i);
            
         //   cout <<result << endl;
            if(result != -1)
            {
                lowIndex = min(lowIndex, result);
            }
        }
        
        return lowIndex == INT_MAX ? -1: lowIndex;
  
    }
};
