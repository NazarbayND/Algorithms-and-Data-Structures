#include <iostream>
#include <vector>

using namespace std;
int coins[] = {1,2,5,10,20,50,100};


vector<int> cou(int s, vector<int> a){
    vector<int> c = a;
    int j = 6;
    while(s > 0){
        if(j == 0){
            break;
        }
        while (s < coins[j]){
            j--;
        }
        while( s >= coins[j]  && c[j] > 0){
            s -= coins[j];
            c[j]--;
        }
        j--;
    }
        if(s == 0){
            cout<<"Transaction accepted!"<<endl;
            return c;
        }
        else {
            cout<<"Transaction stopped!"<<endl;
            return a;
        }
}

int main() {
    vector<int> c(7);
    for(int i = 0; i < 7; i++){
       cin>>c[i];
    }
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int s;
        cin>>s;
        c = cou(s,c);
    }

    return 0;
}