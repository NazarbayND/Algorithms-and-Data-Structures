#include <iostream>
#include <vector>

using namespace std;
vector<int> edges[1001000];
bool visited[1001000]; 



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
    while( cin >> x){
        if(x == 0) break;
        cin>>y;
        x--;
        y--;
        edges[x].push_back(y);
    }
    bool res = true;
    dfs(b-1);
    for (int i = 0; i < a; i++)
        if (!visited[i]) {
            res = false;
            break;
        }
    
    if(res) cout <<"Yes" <<endl;
    else cout << "No"<<endl;

    return 0;
}
