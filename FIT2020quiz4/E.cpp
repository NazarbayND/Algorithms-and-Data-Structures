#include <iostream>
#include <vector>

using namespace std;

bool check(string s){
    if(s.size() > 4) return false;
  
    for(int i = 0; i < s.size(); i++){
         for(int j = i + 1; j < s.size(); j++){
             if(s[i] == s[j]) return false;
        }
    }
    return true;
}

int main() {
    int a;
    cin>>a;

    while(true){
        a++;
        string b = to_string(a);
        if(check(b)) {
            cout<<b<<endl;
            break;
        }

    }

    return 0;
}