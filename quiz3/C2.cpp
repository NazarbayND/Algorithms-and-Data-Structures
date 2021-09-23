#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int a[1010][1010];
bool b[1010][1010];
int c[1010][1010];
int main() {
 int n, m, x, y;
 cin >> n >> m;
 for(int i = 1; i <= n; i++){
  for(int j = 1; j <= m; j++){
   cin >> a[i][j];
   a[i][j] ^= 1;
  }
 }
 cin >> y >> x;
 queue <pair<int, int> > q;
 q.push(make_pair(x, y));
 b[x][y] = true;
 while(!q.empty()){
  pair<int , int> z = q.front();
  x = z.first;
  y = z.second;
  q.pop();
  if(a[x + 1][y] && !b[x + 1][y]){
   c[x + 1][y] = c[x][y] + 1;
   b[x + 1][y] = true;
   q.push(make_pair(x + 1, y));
  }
  if(a[x - 1][y] && !b[x - 1][y]){
   c[x - 1][y] = c[x][y] + 1;
   b[x - 1][y] = true;
   q.push(make_pair(x - 1, y));
  }
  if(a[x][y + 1] && !b[x][y + 1]){
   c[x][y + 1] = c[x][y] + 1;
   b[x][y + 1] = true;
   q.push(make_pair(x, y + 1));
  }
  if(a[x][y - 1] && !b[x][y - 1]){
   c[x][y - 1] = c[x][y] + 1;
   b[x][y - 1] = true;
   q.push(make_pair(x, y - 1));
  }
 }
 cin >> y >> x;
 if(!b[x][y])cout<<-1<<endl;
 else cout << c[x][y]<<endl;
 return 0;
}