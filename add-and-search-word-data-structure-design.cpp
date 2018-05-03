
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class WordDictionary2 {
public:
    /** Initialize your data structure here. */
    WordDictionary2() {
        len = 100;
        ch = new int*[len];
        for (int i = 0; i < len; i++) {
            ch[i] = new int[30];
            for (int j = 0; j < 30; j++){
                ch[i][j] = 0;
            }
        }

        poschs = new int*[len];
        for (int i = 0; i < len; i++) {
            poschs[i] = new int[30];
            for (int j = 0; j < 30; j++) {
                poschs[i][j] = 0;
            }
        }
        pos = new int[len];
        for (int i = 0; i < len; i++) {
            pos[i] = -1;
        }
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        m_data.insert(std::make_pair(word, true));
        int len = word.length();
        for(int i = 0; i < len; i++) {
            if (word[i] == '.') continue;
            if (ch[i][word[i] - 'a'] == 0) {
                poschs[i][++pos[i]] = word[i];
                ch[i][word[i] - 'a'] = 1;
            }
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.length();
        return find_from_pos(word, 0, len);
    }

    bool find_from_pos(string& word, int from, int len) {
        if (from >= len) {
            return m_data.find(word) != m_data.end();
        }
        if (word[from] != '.') {
            return find_from_pos(word, from + 1, len);
        }
        for (int i = 0; i <= pos[from]; i++) {
            int bk = word[from];
            word[from] = poschs[from][i];
            if (find_from_pos(word, from + 1, len)) return true;
            word[from] = bk;
        }
        return false;
    }

    unordered_map<string, bool> m_data;
    int len;
    int** poschs;
    int* pos;
    int** ch;
};


class WordDictionary {
public:

    typedef struct TrieNode {
        char ch;
        bool exist;
        struct TrieNode* children[30];
        TrieNode(char c) {
            ch = c;
            exist = false;
            for (int i = 0; i < 30; i++) {
                children[i] = NULL;
            }
        }
    }TrieNode;

    WordDictionary() {
        root = new TrieNode('_');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len = word.length();
        TrieNode* cur = root;
        for (int i = 0; i < len; i ++) {
            char ch = word[i];
            if (cur->children[ch - 'a'] == NULL) {
                cur->children[ch - 'a'] = new TrieNode(ch);
            }
            cur = cur->children[ch - 'a'];
        }
        cur->exist = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.length();
        TrieNode* cur = root;
        return find_from_pos(word, cur, 0, len);
    }

    bool find_from_pos(string word, TrieNode* cur, int pos, int len) {
        if (cur == NULL) {
            return false;
        }
        if (pos >= len) return cur->exist;
        if (word[pos] != '.') {
            if (cur->children[word[pos] - 'a']) {
                return find_from_pos(word, cur->children[word[pos] - 'a'], pos + 1, len);
            } else {
                return false;
            }
        } else {
            for (int i = 0; i < 30; i++) {
                if (cur->children[i]) {
                    if (find_from_pos(word, cur->children[i], pos + 1, len)) return true;
                }
            }
            return false;
        }
    }



    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

/*
 *
 * ["WordDictionary","addWord","addWord","addWord","addWord","addWord","addWord","addWord","addWord","search","search","search","search","search","search","search","search","search","search"]
[[],["ran"],["rune"],["runner"],["runs"],["add"],["adds"],["adder"],["addee"],["r.n"],["ru.n.e"],["add"],["add."],["adde."],[".an."],["...s"],["....e."],["......."],["..n.r"]]
 */
int main(int argc, char* argv[]) {

    WordDictionary dic;
    dic.addWord("at");
    dic.addWord("and");
    dic.addWord("an");
    dic.addWord("add");
    dic.addWord("a");
    //std::cout << dic.search("a") << std::endl;
    //std::cout << dic.search(".at") << std::endl;
    dic.addWord("bat");
    //std::cout << dic.search(".at") << std::endl;
    //std::cout << dic.search("an.") << std::endl;
    //std::cout << dic.search("a.d.") << std::endl;
    std::cout << dic.search("b.") << std::endl;
    //std::cout << dic.search("a.d") << std::endl;
    //std::cout << dic.search(".") << std::endl;
    return 0;
}

