#include <iostream>
#include <vector>

using namespace std;

int prefix_function(string s, int m) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) { 
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
        if(p[i] == m){
            return m;
        }
    }
    return p[n - 1];
}

int main() {
    string s, t;
    cin >> s >> t;
    string b = t + "#" + s; 
    int j = prefix_function(b, t.size());
    if(j < t.size()){
        s.append(t.substr(j));
    }
    cout<<s<<endl;
    return 0;
}
