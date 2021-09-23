#include <iostream>
#include <vector>

using namespace std;

int pre(string s, int m) {
    int n = s.size();
    vector<int> p(n, 0); //vector sozdaem
    for (int i = 1; i < n; i++) { //po stringu proxodim
        int j = p[i - 1]; // j di beremiz
        while (j > 0 && s[i] != s[j]) //proveryaem esli dva stringa sovpadaet ili net
            j = p[j - 1]; //esli net to do konsa spuskaemsya
        if (s[i] == s[j]) //esli da to podnimaem
            j++;
        p[i] = j; // i dovablieam j na massiv
        if (p[i] == m){
            return i; //esli eto rovno size u nawego stringa to vozvrawaem index 
        }
    }
    return -1; // esli ne vstretili shift otpravim -1
}
int main() {
    string s, t;
    cin >> s >> t; //eki stringti okimiz
    int size = t.size(); //stringtin uzindigi
    s = t + "#" + s + s; // abcde edabc edabc#abcdeabcde
    int p = pre(s, size);

    if(2 * size - p == 0){ //esli p sizega ten bosa shift jok
        cout<< 0 <<endl;
    }
    else if(p == -1){ //voobwe shift jok bolsa -1 boladi
        cout<<"Understandable have a nice day"<<endl;
    }
    else { //olar bolmasa bar degen soz
        cout<< 3 * size - p<<endl;
    }
    return 0;
}
