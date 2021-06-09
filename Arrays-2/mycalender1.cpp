
/* Time limit exceeded with min heap implementaiton*/
class MyCalendar {
public:
  
    typedef pair<int, int> pd;
    
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
        {
             return a.first < b.first;
        }
    };
    
    
    bool insert(priority_queue<pd,vector<pd>, myComp>g, int start, int end)
    {
        // Loop to print the elements
        // until the priority queue
        // is not empty
        while (!g.empty()) {
            
            auto element = g.top();
            if(element.first < end && start < element.second) return false;//---->Important line in entire code to check for over lap of interval .
            g.pop();
        }
        return true;
    }
   
    priority_queue<pd, vector<pd>, myComp> p1;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        if(insert(p1, start , end))
        {
            p1.push(make_pair(start, end));
            return true;
        }
        return false;
     
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
