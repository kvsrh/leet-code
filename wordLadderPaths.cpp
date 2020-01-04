126. Word Ladder II
Hard

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return an empty list if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, 
                                       string endWord, 
                                       vector<string>& wordList) {
        
        unordered_set<string> set(wordList.begin(), wordList.end());
        
        queue<vector<string>> q;
        
        vector<vector<string>> result;
         
        q.push({beginWord});
        
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> next_level;
            for (int i = 0; i < size; i++) {
                vector<string> path = q.front();
                q.pop();
                int path_size = path.size();
                string str = path[path_size-1];
                if (str == endWord) {
                    result.emplace_back(path);
                    found = true;
                }
                
                set.erase(str);
                
                for (int j = 0; j < str.size(); j++) {
                    char c = str[j];
                    for (int k = 0; k < 26; k++) {
                        str[j] = 'a' + k;
                        if (set.find(str) != set.end()) {
                            /*
                            vector<string> path_new = path; // small optimization can be made here. 
                            path_new.emplace_back(str);
                            q.push(path_new);
                            */
                            // the next two lines avoided the copy constructor on the entire path.
                            
                            q.push(path);
                            q.back().emplace_back(str);
                            
                            next_level.insert(str);
                        }
                    }
                    str[j] = c;
                }
            }
            if (found == true) break;
            for (auto e : next_level) {
                set.erase(e);
            }
        }
        
        return result;
        
    }
};

/*
class Solution {
    public:
    /*
        The idea is to run a BFS from beginWord to endWord, while keeping track of the path.
        Once the currWord == endWord, we have found the shortest path.
        The nextLevel keeps track of all the words reachable from currLevel.
        All words in nextLevel should be erased from dict to avoid loops.( This is slight modification to the usual BFS ).
    
    
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set< string > dict( wordList.begin(), wordList.end() );
            dict.erase( beginWord );
            queue< vector< string > > q;
            vector< vector< string > > result;
            q.push( { beginWord } );
            bool found = false;
            while( !q.empty() ) {
                int size = q.size();
                unordered_set< string > nextLevel;

                for( int i = 0 ; i < size ; ++i ) {
                    vector< string > currLevel = q.front();
                    q.pop();
                    string currWord = currLevel.back();
                    if( currWord == endWord ) {
                        found = true;
                        result.push_back( currLevel );
                    } else {
                        for( int i = 0 ; i < currWord.size() ; ++i ) {
                            char orig = currWord[ i ];
                            for( char ch = 'a' ; ch <= 'z' ; ++ch ) {
                                if( ch == orig ) continue;
                                currWord[ i ] = ch;
                                if( dict.find( currWord ) != dict.end() ) {
                                    nextLevel.insert( currWord );
                                    q.push( currLevel );
                                    q.back().push_back( currWord );
                                }
                            }
                            currWord[ i ] = orig;
                        }
                    }
                }
                if( found ) break;
                for( auto n : nextLevel ) {
                    dict.erase( n );
                }
            }
            return result;
        }

}; 
*/
