#include <iostream>
#include <vector>

using namespace std;
string s, t;

vector<int> prefix_function() {
    int n = s.size();
    int sum = 0;
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) { // p[i]
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
        if(p[i] == t.size()) sum++;
    }
    cout<<sum<<endl;
    return p;
}
int main() {
    
    cin >> s >> t;
    s = t + "#" + s;
    vector<int> p = prefix_function();
    for (int i = 0; i < s.size(); i++)
        if (p[i] == t.size())
            cout << i - 2 * t.size() + 1<< " ";
    return 0;
}