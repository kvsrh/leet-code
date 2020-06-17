Cheat sheet - 

permutation formula - 
combination formula -  

vector constructor -
constructor list: 

## GRID DECLARATION AND GRID TRAVERSAL ##

vector<vector<int>> grid(3, vector<>(3,0));

Lookup adjacent elems: 

vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

for (auto & dir : dirs) {
                int nr = r+dir[0];
                int nc = c+dir[1];
                if (nr >= 0 && nr < rows && 
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 'O')
                    q.push({nr,nc});
            }
            

## ~~~ ##


Making pairs -- make_pair()

abs() .. -> get absolute value.

isalpha to see if a character is an alpbhet. 

https://thispointer.com/c-how-to-compare-two-vectors-stdequal-comparators/ - comparison function on vectors. == is overloaded to compare the content of int arrays. 

### RANDOM FUNCTION ###

generate seed - srand() - call it only once in the init() and then keep calling the new values. 
generate random numbers - rand()

### MOD FUNCTION ###
This mod function works  for when a and b are negative. 
int mod(int a, int b) { --> mod for both negative and positive numbers.
    return (b + (a%b)) % b;
}

### SET APIS ### 
1) cleanup all elements in a set:
    set.erase(set.begin(), set.end()); 
2) find if an element is in a set: 
    set.count(num) > 0

### QUEUE APIS ###

q.push() --> insert an element. 
q.front() --> peek the front element.
q.pop() --> Remove the front element.

~~~~ PATTERNS ~~~~ 

## Level order traversal ##

queue<int> q; 
q.push(elem);

while (q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        auto & curr = q.front();
        curr.pop()
        
        // Do something with curr.
        // Add new element based on wheather question is grid or tree.
        
    }
}

## ##

## Processing unequal length strings or linked-list ## 

## ##
