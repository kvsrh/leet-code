https://leetcode.com/problems/reformat-the-string/


// Don't overthing the solution.

class Solution {
public:
    string reformat(string s) {
        
        // If the string length is even - we should have equal number of nums and alphas.
        // If the string length is odd - they should differ by 1. 
        
        string d = "";
        string a = "";
        
        for (auto c : s) {
            isalpha(c) ? a.push_back(c) : d.push_back(c);
        }
       
        if (abs(int(d.size() - a.size())) > 1) { // Remember abs. isalpha ..
            return "";
        
        int dIndex = 0;
        int aIndex = 0;
        int i = 0;
        bool alpha = a.size() > d.size();
        
        while (i < s.size()) {
            if (alpha) {
                s[i++] = a[aIndex++];                
            } else {
                s[i++] = d[dIndex++];
            }
            alpha = !alpha;
        }
        
        return s;
    }
};


/*
class Solution {
public:
    string reformat(string s) {
        string a="",d="";
        // split string into alpha string and digit strings
        for(auto x:s)
            isalpha(x)?a.push_back(x):d.push_back(x);
  
        // if difference is more than 1, return "" since not possible to reformat
        if(abs(int(a.size()-d.size()))>1)
            return "";
        // merge the strings accordingly, starting with longer string
        bool alpha=a.size()>d.size();
        int i=0,j=0,k=0;
            while(i<s.size()){
                if(alpha){
                    s[i++]=a[j++];
                }
                else{
                    s[i++]=d[k++];
                }
                alpha=!alpha;
            }
        return s;
    }
};*/
