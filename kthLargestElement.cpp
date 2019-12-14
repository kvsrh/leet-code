// Finding the k-th largest element in an array!

int findKthLargest(vector<int>& a, int k) {
        
        // Min Heap
        priority_queue <int, vector<int>, greater<int>>heap; 
        
        for(auto u: a)
        {
            if(heap.size()<k)
                heap.push(u);
            else
            {
                if(u>heap.top())
                {
                    heap.pop();
                    heap.push(u);
                }
            }
        }
        return heap.top();
    }

## My solution ##

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Using a priority queue we can keep a context of all the top k elements. 
        
        // Create a min-heap 
        
        int size = nums.size();
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        
        //pq.push(nums[0]);
        
        for (int i = 0; i < size; i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        cout << "size - " << pq.size() << endl;
        return pq.top();
    }
};
