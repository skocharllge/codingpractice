class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int start = 0;
        int end = 0;
        int count = 0;
        string tempStr;
        std::map<char, int>myMap;
        int maxLength = 1;
        size_t n = s.length();

        if (n * k == 0) {
            return 0;
        }
        for(end = 0;end < s.length(); end++)
        {
 
            myMap[s.at(end)] = end;
         

            if(myMap.size() == k+1 )
            {
                int lowestIndex = INT_MAX;
                for( auto itr:myMap)
                {
                     lowestIndex = min(lowestIndex, itr.second);
                }
                myMap.erase(s[lowestIndex]);
                start = lowestIndex + 1;

            }
             maxLength = max(maxLength, (end - start)+1);
        }
        return maxLength;
        
    }
};
