#include <iostream>
#include <vector>

using namespace std;

vector<int> polindrom_even(string s){
    int n = s.size();
    vector<int> d(n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
    int k = i > r ? 0 : min(d[l+r-i+1], r-i+1);
    while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
    d[i] = k;
    if (i+k-1 > r)
        l = i-k,  r = i+k-1;
    }
    return d;
}

vector<int> polindrom_odd(string s){
    int n = s.size();
    vector<int> d(n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
    int k = i>r ? 1 : min(d[l+r-i], r-i+1);
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
    d[i] = k;
    if (i+k-1 > r)
        l = i-k+1,  r = i+k-1;
    }
    return d;
}

int main() {
    string s;
    cin>>s;
    vector<int> d;
    if(s.size() % 2 == 0)
        d = polindrom_even(s);
    else d = polindrom_odd(s);
    for(int i = 0; i < d.size(); i++){
       cout<<d[i]<<" ";
    }
    return 0;
}