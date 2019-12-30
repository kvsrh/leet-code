// GG solution - using stacks and pointers to iterators. WOW! 

class NestedIterator {
public:
    typedef vector<NestedInteger>::iterator iter;  
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    int next() {
        return begins.top()++->getInteger();
    }
    bool hasNext() {
        while(!begins.empty()) {
            iter it = begins.top();
            if(it == ends.top()) {
                begins.pop();
                ends.pop();
                if(!begins.empty()) begins.top()++;
            } else if (it->isInteger()) return 1;
            else {
                vector<NestedInteger>& lst = it->getList();
                begins.push(lst.begin());
                ends.push(lst.end());
            }
        }
        return 0;
    }
private:
   stack<iter> begins, ends;
};

// Simpler solution: 

class NestedIterator {
private: 
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >= 0; i--) {
            
            s.push(nestedList[i]);
        }         
    }

    int next() {
        NestedInteger top = s.top();
        s.pop();
        return top.getInteger();
    }

    bool hasNext() {
        while(!s.empty()) {
            NestedInteger top = s.top();
            if (top.isInteger()) {
                return 1;
            }
            
            vector<NestedInteger> & list = top.getList();
            s.pop();
            
                for(int i = list.size()-1; i >= 0; i--) {
                    
                    s.push(list[i]);
                }
        }
        return 0;
    }
};

In the intial draft of the solution I tried to make the solution work by pushing elements onto the stack in the next function,
which isn't entirely correct since we might have empty NestedIntegers. 
