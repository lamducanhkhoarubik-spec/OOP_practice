#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int countRecur(int n, vector<int> &memo){
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (memo[n] != -1){
        return memo[n];
    }
    memo[n] = countRecur(5,memo) + countRecur(3,memo)+countRecur(1,memo);
    return memo[n];
}
/*Cho N loại đồng xu và giá tiền của mỗi loại là các số nguyên v1,v2,...,vn và số nguyên dương S. Tìm số đồng xu nhỏ nhất để tổng giá trị của chúng bằng S (số lượng đồng xu không giới hạn)*/
int coinChange(vector<int> &coins, int amount){
    int s[10001];
    s[0] = 0;
    for (int i = 1; i <= amount; ++i){
        s[i] = -1;
    }
    for (int i = 1; i <= amount; ++i){
        for (int j = 0; j < coins.size(); ++j){
            if (coins[j] <= i && s[i - coins[j]] != -1){
                if (s[i] != -1){
                    s[i] = min(s[i-coins[j]] + 1,s[i]);
                }
                else{
                    s[i] = s[i-coins[j]] + 1;
                }
            }
        }
    }
    return s[amount];
}
//Unbouned Knapsack
int knapSack(int cap, vector<int> &val, vector<int> &wt){
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1;i <=n; ++i){
        for (int j = 1; j <= cap;++j){
            if (wt[i - 1] <= j){
                dp[i][j] = max(dp[i-1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][cap];
}
//Coin Change
int change(int amount, vector<int>& coins){
    int dp[10001];
    dp[0] = 1;
    for (int i = 1; i <= amount; ++i){
        dp[i] = 0;
    }
    for (int i = 0; i < coins.size(); ++i){
        for (int j = coins[i]; j <= amount; ++j){
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    return dp[amount];
}
// SubSetSum problem
bool isSubsetSum(vector<int> arr, int sum){
    vector<int> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < arr.size(); ++i){
       for (int j = sum; j >= arr[i]; j--){
        dp[j] = (dp[j] || dp[j - arr[i]]); 
       }
    }
    return dp[sum];
}
//Target Sum (Total Ways)
int totalWays(vector<int> &arr, int target){
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i){
        sum += arr[i];
    }
    if (abs(target) > sum || (target + sum) % 2 != 0) return 0;
    int s = (target + sum) / 2;
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 0;i < arr.size(); ++i){
        for (int j = s; j >= arr[i]; j--){
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    return dp[s];
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,0));
    
      
}
int main(int argc, char *argv[]){
    vector<int> arr = {1,1,1,1,1};
    int sum = 3;
    cout << totalWays(arr, sum);
}