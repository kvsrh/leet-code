class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> myPq;

        for (int i = 0; i < points.size(); ++i)
            myPq.push(make_pair(points[i][0]*points[i][0]+points[i][1]*points[i][1],i));

        vector<vector<int>> res;
        for (int i = 0; i < K; ++i) {
            res.push_back(points[myPq.top().second]);
            myPq.pop();
        }

        return res;
    }
};
