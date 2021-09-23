#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    getline(cin,str);
    int x = 1;
    stack<int> st;
    for(int i = 0; i < str.size(); i++){
        cout<<str[i];
       if(str[i] == ' '){
           if(st.top() && st.top() < x){
               st.push(i - x);
               st.push(x);
           }
           x = 1;
       }
       x++;
    }

    int n = st.top();
    st.pop();
    int s = st.top();
    for(int i = s; i < s + n; i++){
       cout<<str[i];
    }

    return 0;
}


