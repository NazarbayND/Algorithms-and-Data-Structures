#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check_anagram(string a, string b){
  
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0;
    int l = 0;
    for(int i = 0; i < a.size(); i++){
        while(a[i] > b[l]){
            l++;
        }
        if(a[i] == b[l]){
           l++;
        }
        else res++;
    }   
    return res;
}

int main() {
    string a,b;
    cin>>a>>b;
    cout<<check_anagram(a,b);
    return 0;
}