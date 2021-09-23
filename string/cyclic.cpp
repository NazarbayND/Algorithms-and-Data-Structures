#include <iostream>
#include <vector>

using namespace std;

int prefix_function(string s, int m) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) { // p[i]
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
        if (p[i] == m){
            return i;
        }
    }
    return -1;
}
int main() {
    string s, t;
    cin >> s >> t;
    int size = t.size();
    s = t + "#" + s + s;
    int p = prefix_function(s, size);

    if(2 * size - p == 0){
        cout<<0<<" ";
    }
    else if(p == -1){
        cout<<-1<<" ";
    }
    else {
        cout<< 3 * size - p <<" ";
    }
    return 0;
}
