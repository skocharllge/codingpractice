//monotonic stacks 
class StockSpanner {
public:
    
    std::stack<std::vector<int>>myStack;
   
    StockSpanner() {
        
        
    }
    
    int next(int price) {
        
        int answer = 1;

        while(!myStack.empty())
        {

          auto topElement = myStack.top();

          if(topElement[0] <= price)
          {
              myStack.pop();
              answer += topElement[1];
          }
          else
          {
              break;
          }
        }
      
        myStack.push({price, answer});
        
        return answer;
      
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
