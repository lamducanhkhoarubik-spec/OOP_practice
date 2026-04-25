#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
//BFS
vector<int> bfs(vector<vector<int>>&adj){
    vector<int> res;
    int n = adj.size();
    vector<bool> visited(n,false);
    queue<int> q;
    int src = 0;
    visited[src] = false;
    q.push(src);
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int x : adj[curr]){
            if (!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}
//DFS
vector<int> dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int>&res){
    visited[s] = true;
    res.push_back(s);
    for (int i : adj[s]){
        if (!visited[i]){
            dfsRec(adj, visited, i, res);
        }
    }
}
vector<int> dfs(vector<vector<int>>&adj){
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
}
//Find if there is a path between two vertices
bool bfs1(int n, vector<vector<int>> &edges, int src, int dest){
        vector<bool> visited(n, false);
        visited[src] = true;
        queue<int> q;
        q.push(src);
        while (!q.empty()){
            int curr = q.front();
            q.pop();

            if (curr == dest) return true;
            for (int neighbor : edges[curr]){
                if (!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        return bfs1(n,edges,source, destination);
    }
//Detect cycle in a directed graph
bool isCycleUtil(vector<vector<int>>&adj,int u, vector<bool> &visited, vector<bool>&restack){
    if (restack[u]) return true;
    if (visited[u]) return false;
    visited[u] = true;
    restack[u] = true;
    for (int v : adj[u]){
        if (isCycleUtil(adj, v, visited, restack)){
            return true;
        }
    }
    restack[u] = false;
    return false;
}
void quickSort(int a[], int left, int right){
    int i, j, x;
    x = a[(left+right)/2];
    i = left;
    j = right;
    while (i <= j){
        while (a[i] < x) i++;
        while(a[j] >x) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(a,left, j);
    if (i < right) quickSort(a,i, right);
}
//Part 2: coding DSA 24-25 UIT


void st
int main (int argc, char *argv[]){
    int a[7] = {4,9,5,6,10,2,3};
    quickSort(a, 0,6);
    for (int i = 0;i < 7;++i){
        cout <<a[i]<<" ";
    }
}