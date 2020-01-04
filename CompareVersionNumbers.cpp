I tried using strtok - but it is a re-enterant function and therefore it can't be used for processing two strings parallel. 
Stackoverflow has suggestions for using strstr_r - which can save context. 

I like this pattern which people use for keeping the code elegant when the strings sizes can be different - 

while (i < size1 && j < size2) {
  int num1 = 0;
  int num2 = 0;
  
  and check inside if we can access inside the second string or the first string. 
}


class Solution {
public:
    // Considering all strings are 
    int compareVersion(string version1, string version2) {
        int result = 0;
        
        int size1 = version1.size();
        int size2 = version2.size();
        
        char * cstr1 = new char[size1+1];
        char * cstr2 = new char[size2+1];
        
        strcpy(cstr1, version1.c_str());
        strcpy(cstr2, version2.c_str());
        
        char * token1 = strtok(cstr1, ".");
        char * token2 = strtok(cstr2, ".");
        
        while (token1 != NULL && token2 != NULL) {
            int digit1 = stoi(token1);
            int digit2 = stoi(token2);
            
            cout << "digit1 - " << digit1 << " digit2 - " << digit2 << endl;
            
            if (!(digit1 == digit2)) {
                return digit1 > digit2 ? 1 : -1;
            }
            token1 = strtok(NULL, ".");
            token2 = strtok(NULL, ".");
            cout << "token1 - " << token1 << " token2 - " << token2 << endl;
        }
        char * token = NULL;
        
        if (token1 == NULL) {
            token = token2;
            result = -1;
        } else {
            token = token1;
            result = 1;
        }
        
                
        while (token != NULL) {
            if (stoi(token) == 0) {
                token = strtok(NULL, ".");
                continue;
            } else {
                return result;
            }
        }
                
        return 0;
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1 = version1.size();
        int size2 = version2.size();
        int i=0, j=0;
        
       
       while(i<size1 || j<size2)
       {
           int num1 = 0;
           int num2 = 0;
           while(i<size1 && version1[i]!='.') 
            {
                num1 = num1*10 + version1[i]-'0';
                i++;
            }
            while(j<size2 && version2[j]!='.')
            {
                num2 = num2*10 + version2[j]-'0';
                j++;
            }
            
            if(num1 > num2)           
                return 1;
            else if(num1< num2)
                return -1;
            i++;
            j++;  
       }
       
       return 0;   
    }
};
