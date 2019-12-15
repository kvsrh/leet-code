// Find the minimum number of meeting rooms necessary for conducting all the meetings. 


int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(intervals[0].end);
        int room = 1;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < pq.top()) room++;
            else pq.pop();
            pq.push(intervals[i].end);
        }
        return room;
    }

# Vector based solution #

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int size = intervals.size();
        
        if (size  <= 1) return size;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> results;
        
        results.push_back(intervals[0]);
        
        bool new_room = 0;
        
        for (int i = 1; i < size; i++) {
            new_room = 1;
            for (auto & room : results) {
                if (intervals[i][0] >= room[1]) {
                    room = intervals[i];
                    new_room = 0;
                    break;
                }  
            }
            if (new_room == 1) results.push_back(intervals[i]);
        }
        return results.size();
    }
};  

