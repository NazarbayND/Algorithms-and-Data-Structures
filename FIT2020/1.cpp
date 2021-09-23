#include<iostream>
using namespace std;
char c[11][11];
bool b[11][11];
void recursion(int x, int y){
    b[x][y] = true;
    if(c[x - 1][y] == '.' && b[x - 1][y] == false)recursion(x - 1, y);
    if(c[x + 1][y] == '.' && b[x + 1][y] == false)recursion(x + 1, y);
    if(c[x][y - 1] == '.' && b[x][y - 1] == false)recursion(x, y - 1);
    if(c[x][y + 1] == '.' && b[x][y + 1] == false)recursion(x, y + 1);
}
int main(){
    int n;
    cin >> n;
    int x, y;
    cin >> y >> x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    recursion(x, y);
    int count = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(b[i][j])count++;
    cout << count;
}
