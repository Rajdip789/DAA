/**
 *  Design Add and Search Words Data Structure:
 *  
 *  Design a data structure that supports adding new words and finding if a string matches any previously added string.
 * 
 *  Implement the WordDictionary class:
 *  WordDictionary() Initializes the object.
 *  void addWord(word) Adds word to the data structure, it can be matched later.
 *  bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
 *  word may contain dots '.' where dots can be matched with any letter. 
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {

private:

    Node* root;

    // TC - O(m*26) ~ O(m) , m = length of the string
    
    bool searchWord(string s, int pos, int n, Node* node) {
        if(pos == n) {
            return node -> isEnd();
        }

        if(s[pos] == '.') {

            for(int i = 0; i < 26; i++) {
                if(node -> containsKey(i + 'a') && searchWord(s, pos + 1, n, node -> get(i + 'a'))) {
                    return true;
                }
            }

            return false;

        } else if(node -> containsKey(s[pos])) {

            return searchWord(s, pos + 1, n, node -> get(s[pos]));
        
        }

        return false;
    }

public:

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for(char ch : word) {
            if(!node -> containsKey(ch)) {
                node -> put(ch, new Node());
            }

            node = node -> get(ch);
        }

        node -> setEnd();
    }

    bool search(string word) {
        return searchWord(word, 0, word.length(), root);
    }
};


int main() {
    WordDictionary *wd = new WordDictionary();

    wd -> addWord("bad");
    wd -> addWord("dad");
    wd -> addWord("mad");

    cout << wd -> search("pad") << endl;   // 0
    cout << wd -> search("bad") << endl;   // 1
    cout << wd -> search(".ad") << endl;   // 1
    cout << wd -> search("b..") << endl;   // 1
}