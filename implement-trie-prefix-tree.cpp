#include <iostream>
#include <string>
using namespace std;

typedef struct TrieNode {
    char ch;
    struct TrieNode* children[30];
    bool exist;

    TrieNode(char c) {
        ch = c;
        exist = false;
        for (int i = 0; i < 30; i++) {
            children[i] = NULL;
        }
    }
}TrieNode;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('_');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.length();
        TrieNode* cur = root;
        for (int i = 0; i < len; i++) {
            if (cur->children[word[i] - 'a'] == NULL) {
                cur->children[word[i] - 'a'] = new TrieNode(word[i]);
            }
            cur = cur->children[word[i] - 'a'];
        }
        cur->exist = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.length();
        TrieNode* cur = find_from_pos(word, root, 0, len);
        if (cur == NULL || cur->exist == false) return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode* cur = find_from_pos(prefix, root, 0, len);
        if (cur == NULL) return false;
        return true;
    }

    TrieNode* find_from_pos(string word, TrieNode* cur, int pos, int len) {
        if (pos >= len || cur == NULL) return cur;
        if (cur->children[word[pos] - 'a']) {
            return find_from_pos(word, cur->children[word[pos] - 'a'], pos + 1, len);
        } else {
            return NULL;
        }
    }

    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main(int argc, char* argv[]) {

    Trie te;
    te.insert("abc");
    te.insert("adcb");
    std::cout << te.search("ad") << std::endl;
    std::cout << te.search("abc") << std::endl;
    std::cout << te.startsWith("a") << std::endl;
    std::cout << te.startsWith("b") << std::endl;
    return 0;
}