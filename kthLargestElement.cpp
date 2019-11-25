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
