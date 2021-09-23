#include <iostream>
#include <vector>

using namespace std;

void snake_print(vector<vector<int> > a){
    for(int i = 0; i < a.size(); i++){
        if(i % 2 == 0){
            for(int j = 0; j < a[i].size(); j++){
                cout<<a[i][j]<<" ";
            }
        }
        else {
            for(int j = a[i].size() - 1; j >= 0; j--){
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a;
    for(int i = 0; i < n; i++){
       for(int j = 0; i < m; j++){
       cin>>a[i][j];
    }
    }
    snake_print(a);
    return 0;
}