class Solution {
public:
    
    string arrangeWords(string text) {
        
        string s;
        vector<std::pair<string, int>>answer;
        int count = 0;
        
        for(int i = 0; i <= text.size(); i++)
        {

            if(text[i] == ' ' || text[i] == '\0')
            {
                
                answer.push_back(pair<string,int>(s, count++));
                s = "";
            }
            else
            {
                 s.push_back(tolower(text[i]));
            }
           
        }
      
        
       
        sort(answer.begin(), answer.end(), [](std::pair<string, int> a, std::pair<string, int> b){
                             
            
 							                       	if(a.first.length() == b.first.length())
                        							{
                            								return a.second < b.second;
                        							}
                       								return a.first.length() < b.first.length();
                                        
                        							});
        
        string str;
                        
        for(auto s : answer)
        {
            str+=s.first;
            str+=" ";
            
        }
        
        str[0] = toupper(str[0]);
        
        if(str[str.size() -1] == ' ')
        {
            str.pop_back();
        }
        
        return str;
        
    }
};
