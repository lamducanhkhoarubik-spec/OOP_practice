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
bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums){
            sum += num;
        }
        if (sum % 2 != 0) return false;
        sum /= 2;
        
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int num : nums){
            for (int j = sum; j >= num; j--){
                dp[j] = dp[j] ||dp[j-num];
            }
            if (dp[sum]) return true;
        }
        return dp[sum];
    }
    int splitNum(int num) {
        int count = 0;
        int temp = num;
        while (temp > 0){
            temp /= 10;
            count++;
        }
        int total = 1 << count;
        int res = 1e9;
        for (int i = 0; i < total; ++i){
            int sum = 0;
            for (int j =0; j < )
        }
    }
int main(int argc, char *argv[]){
    int count = 0;
        int temp = 4325;
        while (temp > 0){
            temp /= 10;
            count++;
        }
        cout << count;
}