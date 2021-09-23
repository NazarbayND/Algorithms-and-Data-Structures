#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string purify(string a){
    stack<char> res;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '#' && !res.empty()) res.pop();
        else res.push(a[i]);
    }
    string ret;
    while (!res.empty())
    {
        ret += res.top();
        res.pop();
    }
    return ret;
}

int main() {
    string a,b;
    cin>>a>>b;
    
    if(purify(a) == purify(b)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}