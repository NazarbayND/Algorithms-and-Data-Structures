#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int b[110][110], a[110][110];
char c[110][110];
queue<pair<int, int> > q;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            if(c[i][j] == 'H')
                q.push(make_pair(i, j)),
                b[i][j] = 1;
        }
    }
    while(!q.empty()){
        pair<int, int> para = q.front();
        q.pop();
        int x = para.first, y = para.second;
        if((c[x + 1][y] == '.' || c[x + 1][y] == 'S') && !b[x + 1][y]){
            b[x + 1][y] = 1;
            a[x + 1][y] = a[x][y] + 1;
            q.push(make_pair(x + 1, y));
        }
        if((c[x - 1][y] == '.' || c[x - 1][y] == 'S') && !b[x - 1][y]){
            b[x - 1][y] = 1;
            a[x - 1][y] = a[x][y] + 1;
            q.push(make_pair(x - 1, y));
        }
        if((c[x][y + 1] == '.' || c[x][y + 1] == 'S') && !b[x][y + 1]){
            b[x][y + 1] = 1;
            a[x][y + 1] = a[x][y] + 1;
            q.push(make_pair(x, y + 1));
        }
        if((c[x][y - 1] == '.' || c[x][y - 1] == 'S') && !b[x][y - 1]){
            b[x][y - 1] = 1;
            a[x][y - 1] = a[x][y] + 1;
            q.push(make_pair(x, y - 1));
        }
    }
    int cnt = 1e9;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == 'S'){
                if(b[i][j] > 0)cnt = min(cnt, a[i][j]);
            }  
        }
    }
    if(cnt == 1e9) cnt = -1;
    cout << cnt << endl;

    return 0;
}