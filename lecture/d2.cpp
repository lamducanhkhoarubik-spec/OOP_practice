#include <iostream>
#include<vector>
#include<cstring>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
//Connected Graph
vector<vector<int>> createGraph(int V, vector<vector<int>> &edges) {
    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Add each edge to the adjacency matrix
    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        mat[u][v] = 1;
        
         // since the graph is undirected
        mat[v][u] = 1; 
    }
    return mat;
}



int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};
int x_1, y_1, x_2, y_2;
const int N = 1000;
int a[N][N];
int n;
void inp(){
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}
bool isValid(int x, int y){
    if (x < n && x >= 0 && y < n && y >= 0) return true;
    return false;

}
bool dfs_net(int x, int y){
    if (x == x_2 && y == y_2) return true;
    a[x][y] = -1;
    for (int k = 0; k < 4; ++k){
        int x_next = x + X[k];
        int y_next = y + Y[k];
        if(isValid(x_next, y_next)){
            if (dfs_net(x_next,y_next)) return true;
        }
        return false;
    }
}
/*l Subsets: Write a function to print all subsets of a given set of strings.
void PrintSubsets(char* str_arr[], int n);
E.g. str_arr = {“Tom”, “Jerry”, “Fred”}
→ Print to screen: {}, { Tom }, { Jerry }, { Fred }, { Tom, Jerry }, { Tom, Fred }, { Jerry,
Fred }, { Tom, Jerry, Fred }*/
void helper1(int start,int n, char* arr[], char *curr_set[], int curr_size){
    cout <<"{";
    for (int i = 0; i < curr_size; ++i){
        cout << curr_set[i]<<((i == curr_size-1 )?" ":",");
    }
    cout <<"}";
    for (int i = start; i < n; ++i){
        curr_set[curr_size] = arr[i];
        helper1(i + 1, n, arr, curr_set, curr_size + 1); 

    }
}
void PrintSubSets(char *str_arr[], int n){
    char *curr_set[100];
    helper1(0, n, str_arr, curr_set, 0);
}
/*k-Permutation: Write a function to print all k-permutations (without repetition of
each number) of given set of integers.
void k_Permute(int arr[], int n, int k);
Notes: k-Permutations (without repetition of each number) of array A are different
ordered arrangements of all k-element subsets of A.
For example: 𝐴 = { 4, 5, 1 }, 𝑛 = 3, 𝑘 = 2
➔ Print to screen: {4 5} {4 1} {5 4} {5 1} {1 4} {1 5}
➔ {4 4}, {5 5}, … are not accepted since they duplicate number 4 and 5. */
void helper2(int n,int k, int arr[], int curr_set[], int curr_size, bool used[]){
    if (curr_size == k){
        cout <<"{";
        for (int i = 0; i < curr_size;++i){
            cout <<curr_set[i]<<" ";
        }
        cout <<"}";
        return;
    }
    for (int i = 0; i < n;++i){
        if (!used[i]){
        used[i] = true;
        
        curr_set[curr_size] = arr[i];
        helper2( n,k, arr, curr_set, curr_size+1,used);
        used[i] = false;
    }

}
}
void k_Permute(int arr[], int n, int k){
     int curr_set[100];
     bool used[100] = {false};
     helper2(n,k,arr,curr_set, 0,used);
}
/*ll permutation: Write a function to print all permutations of a given string.
void PrintAllPermutation(char* str);
For example: 𝑆 = 𝑎𝑏𝑐
➔ Print to screen: 𝑎𝑏𝑐, 𝑎𝑐𝑏, 𝑏𝑎𝑐, 𝑏𝑐𝑎, 𝑐𝑎𝑏, 𝑐𝑏�*/
void helper3(int n, char *str, char *curr_set, int curr_size, bool used[]){
    if (curr_size == n){
        cout <<"{";
        for (int i = 0; i < curr_size; ++i){
            cout << curr_set[i];
        } 
        cout <<"}";
        return;
    }
    for (int i = 0; i < n; ++i){
        if (!used[i]){
        used[i] = true;
        curr_set[curr_size] = str[i];
        helper3(n, str, curr_set, curr_size + 1, used);
        used[i] = false;
    }
}
}
void PrintAllPermutation(char *str){
     char curr_set[100];
     int n = strlen(str);
     bool used[100] = {false};
     helper3(n, str,curr_set,0,used);
}
/*Given an array of non-negative integers 𝐴 and a value 𝑠, write a function to print all
subsets 𝐴 whose sum is equal to 𝑠.
void PrintAllSubsetsum(int arr[], int n, int s);
E.g. 𝐴 = {1,3,2,5,1,3}, 𝑠 = 5
→ Print to screen: {1,3,1},{5},{3,2},{2,3}, {1,1,3}*/
void helper4(int n, int s, int arr[], int curr_set[], int curr_size, int start){
    int sum = 0;
    for (int i = 0; i < curr_size;++i){
        sum += curr_set[i];
    }
    if (sum == s){
        cout <<"{";
        for (int i = 0; i < curr_size; ++i){
            cout << curr_set[i]<<" ";
        }
        cout<<"}";
        return;
    }
    if (sum > s){
        sum = 0;
        return;
    }
    for (int i = start; i < n; ++i){
        curr_set[curr_size] = arr[i];
        helper4(n,s,arr,curr_set, curr_size+1,i +1);
    }
    
}

void PrintAllSubsetsum(int arr[], int n, int s){
     int curr_set[100];
     helper4(n,s,arr,curr_set,0,0);
}
/* Given an array of positive integers 𝐴 and a value 𝑠, write a function to print all unique
combinations in 𝐴 where the sum is equal to 𝑠. (One element in 𝐴 can be repeated
unlimited times in a combination)
E.g. 𝐴 = {2,4,6,8}, 𝑠 = 8
→ Print to screen: {2,2,2,2},{2,2,4},{2,6},{4,4}, {8}
 𝐴 = {2,4,6,8}, 𝑠 = 1
→ Print to screen: 𝑁𝑜 𝑠𝑜𝑙𝑢𝑡𝑖𝑜𝑛
*/
void helper5( int start,int n,int s, int arr[], int curr[], int curr_size){
   int sum = 0;
   for (int i = 0; i < curr_size;++i){
    sum += curr[i];
   }
   if (sum == s){
    cout <<"{";
    for (int i = 0; i < curr_size; ++i){
        cout <<curr[i]<<" ";
    }
    cout<<"}";
   return;
   }
   if (sum > s){
    return;
   }
   for (int i = start; i < n; ++i){
       curr[curr_size] = arr[i];
       helper5(i ,n,s,arr, curr, curr_size+1);

   }
}
void combinationalSum(int arr[],int n, int s){
    int curr[100];
    
    helper5(0,n,s,arr,curr, 0);
}
/*Letter Case Permutation.
Given a string containing alphabetic characters, write a function to return all possible
letter case permutations of the string (i.e., convert it to uppercase or lowercase).
Example:
Input: "a1b2"
Output: "a1b2", "a1B2", "A1b2", "A1B2"*/
void helper6(char*str, int index){
    if (index == strlen(str)){
        cout <<str<<" ";
        return;
    }
    if (isdigit(str[index])){
        helper6(str, index+1);
    }
    else{
        str[index] = tolower(str[index]);
        helper6(str, index+1);
        str[index] = toupper(str[index]);
        helper6(str,index +1);
    }
}
int main() {
    char s[] = "a1b2";
   helper6(s,0);
    return 0;
}