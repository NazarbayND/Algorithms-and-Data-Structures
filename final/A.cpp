#include <iostream>
#include <vector>
#include <map>


using namespace std;
vector<pair<int, pair<int, int> > > v[1000100];
map<string, bool> m;
int sz;
string s;
char c;
void go(int n = 0, int k = 0){
    if(k == s.size())return;
    for(int i = 0; i < v[n].size(); i++){
        if(v[n][i].first == s[k]){
            if(c == '+')
                v[n][i].second.first++;
            else
                v[n][i].second.first--;
            go(v[n][i].second.second, k + 1);
            return;
        }
    }
    v[n].push_back(make_pair(s[k], make_pair(1, ++sz)));
    go(sz, k + 1);
}
int ask(int n = 0, int k = 0){
    for(int i = 0; i < v[n].size(); i++){
        if(v[n][i].first == s[k]){
            if(k == s.size() - 1)
                return v[n][i].second.first;
            return ask(v[n][i].second.second, k + 1);
        }
    }
    return 0;
}
void solve(){
    cin >> c >> s;
    if(c == '?')
        cout << ask() << endl;
    else if(c == '+')
        m[s] = true;
    else if(m[s]) m[s] = false;
    else return;
    if(c != '?')go();
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
