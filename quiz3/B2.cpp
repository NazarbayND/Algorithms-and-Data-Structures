#include<iostream> 
#include<list> 
#define MAX_CHAR 256 
using namespace std; 
  
class SuffixTrieNode 
{ 
private: 
    SuffixTrieNode *children[MAX_CHAR]; 
    list<int> *indexes; 
public: 
    SuffixTrieNode()
    { 
       
        indexes = new list<int>; 
  
      
        for (int i = 0; i < MAX_CHAR; i++) 
          children[i] = NULL; 
    } 
  
 
    void insertSuffix(string suffix, int index); 
  
    
    list<int>* search(string pat); 
}; 
  

class SuffixTrie 
{ 
private: 
    SuffixTrieNode root; 
public: 
    void insert(string txt) 
    { 
    
        for (int i = 0; i < txt.length(); i++) 
            root.insertSuffix(txt.substr(i), i); 
    } 
  
    // Function to searches a pattern in this suffix trie. 
    void search(string pat); 
}; 
  
// A recursive function to insert a suffix of the txt in 
// subtree rooted with this node 
void SuffixTrieNode::insertSuffix(string s, int index) 
{ 
    // Store index in linked list 
    indexes->push_back(index); 
  
    // If string has more characters 
    if (s.length() > 0) 
    { 
        // Find the first character 
        char cIndex = s.at(0); 
  
        // If there is no edge for this character, add a new edge 
        if (children[cIndex] == NULL) 
            children[cIndex] = new SuffixTrieNode(); 
  
        // Recur for next suffix 
        children[cIndex]->insertSuffix(s.substr(1), index+1); 
    } 
} 
  
// A recursive function to search a pattern in subtree rooted with 
// this node 
list<int>* SuffixTrieNode::search(string s) 
{ 
    // If all characters of pattern have been processed, 
    if (s.length() == 0) 
        return indexes; 
  
    // if there is an edge from the current node of suffix trie, 
    // follow the edge. 
    if (children[s.at(0)] != NULL) 
        return (children[s.at(0)])->search(s.substr(1)); 
  
    // If there is no edge, pattern doesn’t exist in text 
    else return NULL; 
} 
  
/* Prints all occurrences of pat in the Suffix Trie S (built for text)*/
void SuffixTrie::search(string pat) 
{ 
    // Let us call recursive search function for root of Trie. 
    // We get a list of all indexes (where pat is present in text) in 
    // variable 'result' 
    list<int> *result = root.search(pat); 
  
    // Check if the list of indexes is empty or not 
    if (result == NULL) 
        cout << "NO" << endl; 
    else
    { 
      cout<< "YES" <<endl;
    } 
} 
  
// driver program to test above functions 
int main() 
{ 
    SuffixTrie S; 
    for(int i =0; i < 7; i++){
        char a;
        string b;
        cin>>a>>b;
        if (a == 'A'){
            S.insert(b);
        }
        else {
            S.search(b);
        }
    }
   
    return 0; 
}