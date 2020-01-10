621. Task Scheduler
Medium

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Interesting? 
        // See if you work through enough examples the pseudo code made life easier.
        unordered_map<char,int> hash;
        
        for (auto e : tasks) {
            if (hash.find(e) != hash.end()) {
                hash[e]++;
            } else {
                hash[e] = 1;
            }
        }
        
        priority_queue<int,vector<int>> pq;
        
        for (auto e : hash) {
            pq.push(e.second);
        }
        
        int high_count = pq.top();
        pq.pop();
       // cout << high_count << endl;
        int inital_spots = high_count + n*(high_count-1);
        int spots = inital_spots;
        int empty_spots = n*(high_count-1);
        
        while(empty_spots != 0 &&
              !pq.empty() &&
              pq.top() == high_count) {
            spots++;
            empty_spots -= (high_count-1);
            pq.pop();
        }
       // cout << spots << endl;
        
        int spare_spots = 0;
        
        while (!pq.empty()) {
            spare_spots += pq.top();
            pq.pop();
        }
        
        if (spare_spots > empty_spots) {
            return spots + spare_spots - empty_spots;
        } else {
            return spots;
        }
        
        
    }
};

Notes: 

Have a min heap to find the intial number of spots and then keep adding spot++ until the max-heap returns same value as the
inital top val. Then see if we have enough empty spots to fill the rest of the elements and if not add as many more necessary
places. 
