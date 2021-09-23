#include <iostream>
#include <vector>

using namespace std;
vector<int> edges[1000000];
bool visited[1000000]; 



void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < edges[v].size(); i++) {
        int j = edges[v][i];
        if (!visited[j]) 
            dfs(j);
    }
}

int main(){
    int a, b, x, y;
    cin >> a >> b;
    for (int i = 0; i < b; i++) {
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int res = 0;
    for (int i = 0; i < a; i++)
        if (!visited[i]) {
            dfs(i);
            res++;
        }
    cout << res<<endl;
    return 0;
}
