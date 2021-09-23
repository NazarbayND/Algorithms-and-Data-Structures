#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string s) {
    int n = s.size();
    string res = "";
    for(int i = 0; i < n; i++) {
        char c = s[i];
        res += tolower(c);
    }
    return res;
}

int main() {  
    char b;
    string a,s;
    while(cin>>b>>a){
        if(b =='?'){
            if (s.find(toLowerCase(a)) != -1) {
                cout << "Yes" <<endl;
            } else {
                cout<<"No"<<endl;
            }
        } 
        else if(b =='A'){
            s += toLowerCase(a);
        }
    }
    return 0;
}