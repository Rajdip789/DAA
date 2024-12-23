/**
 *  Trie: or prefix tree is a tree data structure used to efficiently store and retrieve keys in a 
 *  dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker etc.
 *  
 *  insert, search and startsWith in the Trie. TC - O(m) 
 *      m = length of word to insert / search string / prefix string to check startwith
 *  As we have to iterate through each character of the word (length m) and Checking or inserting each character 
 *  at a node is O(1), as there are at most 26 links for lowercase English letters.
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    bool isEnd() {
        return flag;
    }
    
    void setEnd() {
        flag = true;
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
        }

        node -> setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++) {
            if(!node -> containsKey(word[i])) {
                return false;
            }
            node = node -> get(word[i]);
        }

        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(int i = 0; i < prefix.size(); i++) {
            if(!node -> containsKey(prefix[i])) {
                return false;
            }
            node = node -> get(prefix[i]);
        }

        return true;
    }
};

int main() {
    Trie trie;

    vector<string> strs = {"apple", "apps", "apxl", "bac", "bat"};

    for(auto str : strs) trie.insert(str);

    cout << trie.search("apple") << endl;       // ouput - 1
    cout << trie.search("app") << endl;         // ouput - 0
    cout << trie.startsWith("apx") << endl;     // ouput - 1
    cout << trie.search("bat") << endl;         // ouput - 1
    
    trie.insert("app");
    cout << trie.search("app") << endl;         // ouput - 1
}