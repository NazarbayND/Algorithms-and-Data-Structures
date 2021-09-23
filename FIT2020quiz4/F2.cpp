#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline( cin, s );

    int n;
    string max;
    string w;

    istringstream is( s );
    n = 0;
    while ( is >> w )
    {
        if ( n < w.size() ) 
        { 
            n = w.size();
            max = w;
        }                     
    }

    cout << max << endl;    
}    