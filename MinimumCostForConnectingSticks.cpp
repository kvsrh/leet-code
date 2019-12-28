
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); return 0;}();


/*
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // Create a min-heap of all the elements in the sticks.
        // Pop top two elements and add to sum and push back the result, until
        // we can pop back two elements.
        
        priority_queue<int,vector<int>, greater<int>> q (sticks.begin(),
                                                         sticks.end());
        
        int cost = 0; 
        
        while (q.size() > 1) {
            int top1 = q.top(); q.pop();
            int top2 = q.top(); q.pop();
            // cout << "top1 - " << top1 << " top2 - " << top2 << endl;
            cost += top1 + top2;
            // cout << "cost - " << cost << endl;
            q.push(top1 + top2);
        }
        
        // cost += q.top();
        
        return cost;
        
    }
};
*/

class Solution {
private:
    int left = 0, right = 0, numSticks, numResults = 0;
    // Gets the minimum from InputSet and ResultSet
    bool getMin(vector<int>& sticks, int &num) {
        // check if there are numbers available from InputSet and ResultSet
        bool f = right < numSticks, s = left < numResults;
        // If number is available from both sets, choose the smallest
        if (f && s) num = (sticks[left] <= sticks[right]) ? sticks[left++] : sticks[right++];
        // If number is available from InputSet only
        else if (f) num = sticks[right++];
        // If number is available from ResultSet only
        else if (s) num = sticks[left++];
        return f || s; // Returns result saying if we could find a number from any one of the Sets.
    }
public:
    int connectSticks(vector<int>& sticks) {
        numSticks = sticks.size();
        sort(sticks.begin(), sticks.end()); // Initial sort
        int result = 0, first, second; // Result and place holders to get the smallest two numbers.
        // Continue till you can get two numbers every time from the Sets.
        while (getMin(sticks, first) && getMin(sticks, second))
            result += sticks[numResults++] = first + second; // Store the sum back in the ResultSet
        return result;
    }
};
