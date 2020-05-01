1419. Minimum Number of Frogs Croaking 

Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.

Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.

Example 4:

Input: croakOfFrogs = "croakcroa"
Output: -1


/*
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        // Croak Croak -- 
        // ^     ^
        // 12345 12345 -- 
        
        // Croak .. Croak .. 
        // CrCroakoak -- Simpler problem - parse {{CR}{C}{CR}{CRO}} 
        
        unordered_map<char,int> map({{'c',1}, {'r',2}, {'o',3}, {'a',4}, {'k',5}});
        
        vector<vector<int>> result;
        
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            bool found = 0;
            char c = croakOfFrogs[i];
            if (map[c] == 1) {
                result.push_back({i});
                continue;
            }
            for (auto & elem : result) {
                if (map[c]-1 == elem.size()) {
                    elem.emplace_back(i);
                    found = 1;
                    break;
                }
            }
            if (!found) return -1;
        }
        
        for (auto elem : result) {
            if (elem.size() < 5) {
                return -1;
            }
        }
        
       
        for (auto & elem : result) {
            int last = elem[elem.size()-1];
            elem.erase(elem.begin()+1, elem.end());
            elem.emplace_back(last);
        }
        
        // for (auto elem : result) {
        //    for (int c : elem) {
        //        cout << c << " ";
        //    }
        //    cout << endl;
        // }
        
        sort(result.begin(), result.end()); // sort based on the start time. 
        
        priority_queue <int, vector<int>, greater<int>> pq;
        
        pq.push(result[0][1]); // maintain pq based on the end time. 
        
        int frogs = 1;
        
        for (int i = 1; i < result.size(); i++) {
            if (result[i][0] < pq.top()) {
                frogs++;
            } else {
                pq.pop();
            }
            pq.push(result[i][1]);
        }
        
        return frogs;
        
    }
};
*/
class Solution {
    public: 
int minNumberOfFrogs(string croakOfFrogs) {
    if(croakOfFrogs.empty())
        return -1;

    int count = 0;          //stores final ans, will get incrememented whenever 'c' encountered.
    int countFreeFrogs = 0; //stores how many frogs have completed,i.e. said 'k''
                            //whenever a 'c' is encountered and countFF > 0, then 
                            //I will not increment count, as a frog is free to croak
                            //again.
    
    int c = 0;              //store count of each character encountered.
    int a = 0;              //these will be incremented/decremented accordingly.
    int r = 0;
    int o = 0;
    int k = 0;

    for(auto ch : croakOfFrogs)
    {
        switch(ch){
            case 'c':
                c++;
                if(countFreeFrogs==0){
                    count++;
                }
                else{
                    countFreeFrogs--;
                }
                break;
            case 'r':
                r++;
                if(c<r)
                    return -1;
                break;
            case 'o':
                o++;
                if(r<o)
                    return -1;
                break;
            case 'a':
                a++;
                if(o<a)
                    return -1;
                break;
            case 'k':
                k++;
                if(a<k)
                    return -1;
                else{
                    c--;             //decrement entire croak if k encountered. 
                    r--; o--;a--;k--;
                    countFreeFrogs++;
                }
                break;
        }
    }
    if(c!=0 || r!=0 || o!=0 || a!=0 || k!=0)
        return -1;
    return count;
}
};
