#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_set>
#define ll long long
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq;
        set<int> s(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); i++){
            freq[nums1[i]]++;
        }
        vector<int> res;
        for (int i : s){
            if (freq[i] > 0){
                res.push_back(i);
            }
            freq[i]--;
        }
        return res;

    }

    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> freq1;
        map<string, int> freq2;
         for (int i = 0; i < words1.size(); ++i){
            freq1[words1[i]]++;
         }
         for (int i = 0; i < words2.size(); ++i){
            freq2[words2[i]]++;
         }
         int count = 0;
         for (string it : words2){
            if (freq1[it]==1 && freq2[it] == 1){
                count++;
            }
         }
         return count;

    }
int main(int argc, char *argv[]){
    vector<string> nums1={"b","bb","bbb"};
    vector<string> nums2={"a","aa","aaa"};
    cout << countWords(nums1, nums2);
}