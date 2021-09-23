#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
        int max = 0;
        int res = 0;
        int a[26];
        for (int i = 0; i < s.size(); i++){
            int j = s[i] - 'a';
            if(a[j] < 1){
                res++;
            }
            else {
                memset(a, 0, 26);
                if(max < res) max = res;
                res = 1;
            }
            a[j] = 1;
        }
            
        return max;
}

int main() {
    cout<<lengthOfLongestSubstring("pwwkew")<<endl;
   return 0;
}