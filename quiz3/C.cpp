#include <iostream>
#include <vector>

using namespace std;

int a[1010][1010];
int c[1010][1010];

bool v[1010][1010];

void dfs(int x, int y, int n){
    if(v[x][y]) return;
    v[x][y] = true;
    c[x][y] = n;
    if(a[x + 1][y] && !v[x + 1][y]){
        dfs(x+1, y, n+1);
    }
    if(a[x - 1][y] && !v[x - 1][y]){
        dfs(x-1, y, n+1);
    }
    if(a[x][y + 1] && !v[x][y + 1]){
        dfs(x, y+1, n+1);
    }
    if(a[x][y - 1] && !v[x][y - 1]){
        dfs(x, y-1, n+1);
    }
}

int main() {
    int x, y;
    cin>>x>>y;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            cin>>a[i][j];
            a[i][j] ^= 1;
        }
    }
    cin >> y >> x;
    dfs(x,y,0);
    cin >> y >> x;
    if(!v[x][y])cout<<-1<<endl;
    else cout << c[x][y] <<endl;

    return 0;
}