#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v;
    set<int> s;
    
    for(int i = 0; i < n; i++){
       int a;
       cin>>a;
       v.push_back(a);
       s.insert(a);
    }

    if(v.size() == s.size()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   return 0;
}