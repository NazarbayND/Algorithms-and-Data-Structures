#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_anagram(string a, string b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a == b) return true;
    else return false;
}

int main() {
    string a,b;
    cin>>a>>b;
    cout<<check_anagram(a,b);
   return 0;
}