#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> a;

void reverse(){
    stack<int> st;
    int size = a.size();
    for(int i = 0; i < size;i++){
        st.push(a[i]);
    }
    for(int i = 0; i < size;i++){
        a[i] = st.top();
        st.pop();
    }
};

int main() {
    int N;
    cin>>N;
    for (int i = 0; i< N; i++){
        int num;
        int ele;
        cin>>num;
        if(num == 1){
            cin>>ele;
            a.push_back(ele);
        }
        else if (num == 2) {
            reverse();
        }
        else {
            break;
        }
    }

    for(int i = 0; i < a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

   return 0;
}
