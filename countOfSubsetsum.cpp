using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    // populate the sum=0 columns, as we will always have an empty set for zero sum
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }

    // with only one number, we can form a subset only when the required sum is
    // equal to its value
    for (int s = 1; s <= sum; s++) {
      dp[0][s] = (num[0] == s ? 1 : 0);
    }

    // process all subsets for all sums
    for (int i = 1; i < num.size(); i++) {
      for (int s = 1; s <= sum; s++) {
        // exclude the number
        dp[i][s] = dp[i - 1][s];
        // include the number, if it does not exceed the sum
        if (s >= num[i]) {
          dp[i][s] += dp[i - 1][s - num[i]];
        }
      }
    }

    // the bottom-right corner will have our answer.
    return dp[num.size() - 1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    int size = num.size();
    vector<vector<int>> dp (size, vector<int> (sum+1,0));

    // using num[0] can we achieve any sum from [0:sum]

    for (int i = 0; i <= sum; i++) {
      dp[0][i] = (num[0] == sum) ? 1 : 0;
    }

    // using num[0] to num[size-1] can we acheive 0 sum. 

    for (int i = 0; i < size; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i < size; i++) {
      for (int j = 1; j <= sum; j++) {
          int first = 0, second = 0;
          if (num[i] <= j) {
              first = dp[i-1][j-num[i]];
          }
          second = dp[i-1][j];
          dp[i][j] = first+second;
      }
    }
    return dp[size-1][sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}
