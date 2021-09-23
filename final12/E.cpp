#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
       cin>>a[i];
    }
    int m;
    cin>>m;
    map<string, string> mp;
    for(int i = 0; i < m; i++){
       string a,b;
       cin>>a>>b;
       mp.insert(a,b);
    }
    string h;
    cin>>h;
    vector<string> res;
    

    return 0;
}