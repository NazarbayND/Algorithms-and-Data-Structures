#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string s){
    for(int i = 0; i < s.size(); i++){
         for(int j = i + 1; j < s.size(); j++){
             if(s[i] == s[j]) return false;
        }
    }
    return true;
}

vector<string> sort(vector<string> a){
    int n = a.size();
    vector<string> res(n);
    for(int i = 0; i < n; i++){
       
    }
}

int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
       cin>>a[i];
    }



    return 0;
}