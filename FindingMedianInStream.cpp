
//static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();

class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        cout << "#S# num - "  << num << " ###" << endl;
        
        int hi_top = hi.size() > 0 ? hi.top() : 0;
        int lo_top = lo.size() > 0 ? lo.top() : 0;
        
        if (num >= hi_top) {
            hi.push(num);
        } else {
            lo.push(num);
        }
        
        if (hi.size() > lo.size()) {
            while (((hi.size() - 1) > lo.size()) && (hi.size() > 0)) {
                cout << "#1# " << lo.size() << " # " << hi.size() << endl;
                lo.push(hi.top());
                hi.pop();
            }
        } else {
            while (((lo.size() - 1) >= hi.size())  && (lo.size() > 0)) {
                cout << "#2# " << lo.size() << " # " << hi.size() << endl;
                hi.push(lo.top());
                lo.pop();
            }
        }
        cout << "#E#  lo - " << lo.size()  << " hi - " << hi.size() << " ###" << endl;
        
        cout << "#E# num - "  << num << "###" << endl;
        cout << "\n" << endl;
        
        return;
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if (lo.size() == hi.size()) {
            return (0.5*(lo.top()+hi.top()));
        } else {
            return hi.top();
        }
    }
};

class MedianFinder {
    priority_queue<int> lo;                              // max heap
    priority_queue<int, vector<int>, greater<int>> hi;   // min heap

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (lo.size() < hi.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};
