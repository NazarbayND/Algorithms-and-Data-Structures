#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        set<int, greater<int> > s;
        for(int i = 0; i < m; i++){
          int a;
          cin>>a;
          if(s.count(a) == 1){
              s.erase(a);
          }
          else {
              s.insert(a);
          }
        }
        int res = s.begin();
        if(res == -1){
            cout<<"ZA WARUDO"<<endl;
        }
        else {
            cout<<res<<endl;
        }

    }
    return 0;
}