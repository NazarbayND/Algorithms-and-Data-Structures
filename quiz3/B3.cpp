#include <iostream>
#include <vector>

using namespace std;

const int N = (int)1e5 + 5; 
int to[N][26];
int vn = 1;

void addWord(string s) {
    int n = s.size();
    int v = 1;
    for(int i = 0; i < n; i++){
        char c = tolower(s[i]) - 'a';
        if(to[1][c] > 0) to[v][c] = to[1][c];
        else if(to[1][c] == 0 && to[v][c] == 0) {
            to[v][c] = ++vn;
            to[1][c] = to[v][c];
        }
        v = to[v][c];
    }
}

bool search(string s) {
    int n = s.size();
    int v = 1;
    for(int i = 0; i < n; i++){
        char c = tolower(s[i]) - 'a';
        if(to[v][c] == 0) return false;
        v = to[v][c];
    }
    return true;
}

int main() {
    char a;
    while(cin>>a){
        string b;
        cin>>b;
        if(a == 'A'){
            addWord(b);
        }
        if(a == '?') {
            if(search(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}