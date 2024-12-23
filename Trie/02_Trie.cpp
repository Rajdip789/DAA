/**
 *  insert, countWordsEqualTo, countWordsStartingWith and erase word in Trie. TC - O(m) 
 *      m = length of word to insert / countWordsEqualTo string / countWordsStartingWith string 
 *  As we have to iterate through each character of the word (length m) and Checking or inserting each character 
 *  at a node is O(1), as there are at most 26 links for lowercase English letters.
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    int cntEndWith = 0;     // count no of words that ends at this node 
    int cntPrefix = 0;      // count no of words that have this node as prefix;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void increaseEnd() {
        cntEndWith++;
    }

    void decreaseEnd() {
        cntEndWith--;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void decreasePrefix() {
        cntPrefix--;
    }
};

class Trie {

private: 
    
    Node *root;

public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++) {
            if(!node -> containsKey(word[i])) {
                node -> put(word[i], new Node());
            }

            node = node -> get(word[i]);
            node -> increasePrefix();
        }

        node -> increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++) {
            if(node -> containsKey(word[i])) {
                node = node -> get(word[i]);
            } else {
                return 0;
            }
        }

        return node -> cntEndWith;
    }

    int countWordsStartingWith(string word) {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++) {
            if(node -> containsKey(word[i])) {
                node = node -> get(word[i]);
            } else {
                return 0;
            }
        }

        return node -> cntPrefix;
    }
    
    void erase(string word) {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++) {
            if(node -> containsKey(word[i])) {
                node = node -> get(word[i]);
                node -> decreasePrefix();
            } else {
                return;
            }
        }

        node -> decreaseEnd();
    }
};

int main() {
    Trie trie; 
    
    trie.insert("apple"); 
    trie.insert("app"); 

    cout << "Inserting strings 'apple', 'app' into Trie...\n"<< endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    
    cout << "\nErasing word 'app' from trie...\n"<< endl;
    trie.erase("app"); 
    
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl; 
    
    return 0; 
}