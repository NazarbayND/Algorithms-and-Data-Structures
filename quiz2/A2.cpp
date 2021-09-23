#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
   return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    int n = p.size();
    int res = n;
    if(p[n - 1] == n - 1) res = 1;
    else res = n - p[n-1];    
    cout<<res<<endl;
    return 0;
}
