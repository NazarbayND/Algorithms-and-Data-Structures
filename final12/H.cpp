#include <iostream>
#include <string>
using namespace std;
 
string get_full_key(string pt, string k){
    if(k.size() >= pt.size())
        return k;
    else{
        int psize = pt.size()-k.size();
        int ksize = k.size(); 
        while(psize >= ksize){
            k += k;
            psize -= ksize;
        }
 
        k += k.substr(0, psize);
        return k;
    }
}
 
string get_encryption(string pt, string k){
 
    string ct = "";
    for(int i=0;i<pt.size();i++)
        ct += (char) (((int)pt[i]-'a' + (int)k[i]-'a') % 26) + 'a';
 
    return ct;
}
 
 
int main(){
    string plaintext;
    cin>>plaintext;
 
    string key;
    cin>>key;
 
    key = get_full_key(plaintext, key);
    string ciphertext = get_encryption(plaintext, key);
 
    cout<< ciphertext <<endl;
 
    
    return 0;
}