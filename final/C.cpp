#include <iostream>
#include <vector>
#include <queue>

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
    vector <pair <int, int> > s;
    int x, y;
    int bx,by;
    int ex,ey;
    cin>>x>>y;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            char d;
            cin>>d;
            if(d == 'H'){
                bx = i;
                by = j;
                a[i][j] = 1;
            }
            if(d == 'S'){
                s.push_back(make_pair(i,j));
                a[i][j] = 1;
            }
            if(d == '.') a[i][j] = 1;
        }
    }
   
    dfs(bx,by, 0);

    int res = x*y + 100;
    for(int i = 0; i < s.size(); i++){
        pair<int , int> z = s[i];
        ex = z.first;
        ey = z.second;
        if(v[ex][ey] && res > c[ex][ey]){
            res = c[ex][ey];
        }
    }
    if(res <= x*y) cout<<res<<endl;
    else cout<<-1<<endl;

    return 0;
}