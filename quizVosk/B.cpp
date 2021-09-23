#include <iostream>
#include <vector>

using namespace std;

bool check(string s){
    for(int i = 0; i < s.size(); i++){
         for(int j = i + 1; j < s.size(); j++){
             if(s[i] == s[j]) return false;
        }
    }
    return true;
}

int main(){
    int l,r;
    cin>>l>>r;

    while(l <= r){
        string b = to_string(l);
        if(check(b)) {
            cout<<b<<endl;
            break;
        }
        l++;   
    }
    if (l > r) cout<<"Understandable, have a great day"<<endl;

    return 0;
}