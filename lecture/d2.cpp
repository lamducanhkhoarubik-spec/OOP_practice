#include <iostream>
#include<vector>
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
void solve(){
    inp();
    cout <<"Nhap toa do bat dau: ";
    cin >> x_1 >> y_1;
    cout <<"Nhap toa do ket thuc: ";
    cin >> x_2 >> y_2;
    if (!isValid(x_1, y_1) || !isValid(x_2, y_2)){
        cout <<"Vi tri khoi tao khong hop le";
        return;
    }
   
    bool ans = dfs_net(x_1, y_1);
    cout <<(ans == true) ? "True" : "False";
}
int main() {
    solve();
    return 0;
}