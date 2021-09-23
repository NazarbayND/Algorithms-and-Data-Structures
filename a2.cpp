#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

struct Voter
{
    string name;
    string vote;
    int weight;
};

string can[] = {"Sharpos", "Pythos", "Jayos"};


int main() {
    int n;
    cin>>n;
    Voter votes[n];
    map<string, int> v[3];
    map<string, int>::iterator itr;
    for(int i = 0; i < n; i++){
        cin>>votes[i].name>>votes[i].weight>>votes[i].vote;
        if(votes[i].vote == can[0]){
            v[0].insert(make_pair(votes[i].name, votes[i].weight));
        }
        else if(votes[i].vote == can[1]){
            v[1].insert(make_pair(votes[i].name, votes[i].weight));
        }
        else {
            v[2].insert(make_pair(votes[i].name, votes[i].weight));
        }
    }
    int res[3];
    for (itr = v[0].begin(); itr != v[0].end(); ++itr) {
        res[0] += itr->second;
    }
     for (itr = v[1].begin(); itr != v[1].end(); ++itr) {
        res[1] += itr->second;
    }
     for (itr = v[2].begin(); itr != v[2].end(); ++itr) {
        res[2] += itr->second;
    }
    int win = 0;
    int w = 0;
    for(int i = 0; i < 3; i++){
        cout<<can[i]<<" "<<res[i]<<endl;
        if(win < res[i]){
            win = res[i];
            w = i;
        }
    }
    cout<<can[w]<<" WIN"<<endl;
    return 0;
}