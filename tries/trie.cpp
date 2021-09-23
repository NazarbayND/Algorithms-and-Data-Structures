#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
        char value;
        int chil_count = 0;
        Node *children[26];
        bool is_word;

        Node(char v){
            this->value = v;
            chil_count = 0;
        }
}


int main() {

   return 0;
}