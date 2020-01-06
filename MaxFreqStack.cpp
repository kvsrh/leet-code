class FreqStack {
public:
    unordered_map<int,stack<int> > latest; Mapping between a given frequency and it's corresponding stack.
    unordered_map<int, int> frequency; Mapping between a given value and it's frequency. 
    int max_freq;

    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        frequency[x]++;
        latest[frequency[x]].push(x);
        max_freq = max(max_freq, frequency[x]);
    }
    
    int pop() {
        int current = latest[max_freq].top();
        latest[max_freq].pop();
        if(latest[max_freq].size() == 0) {
            max_freq--;
        }
        frequency[current]--;
        return current;
    }
};

Notes: look at comments
