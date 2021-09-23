#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    stack<int> s;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        while(!s.empty() && a >= s.top()) {
            s.pop();
        }
        s.push(a);
    }
    cout<<s.size()<<endl;
    return 0;
}