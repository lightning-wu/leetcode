#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


int w[] = {-1, 0, 1, 0};
int h[] = {0, -1, 0, 1};

typedef struct TrieNode {
    struct TrieNode* children[30];
    char ch;
    bool word;
    bool occur;

    TrieNode(char c) {
        ch = c;
        word = false;
        occur = false;
        for (int i = 0; i < 30; i++) {
            children[i] = NULL;
        }
    }
}TrieNode;


class Solution2 {
public:

    Solution2() {
        root = new TrieNode('_');
        visit = NULL;
        ih = 0;
        iw = 0;
    }

    void init_visit() {
        for (int i = 0; i < ih; i++) {
            for (int j = 0; j < iw; j++) {
                visit[i][j] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        ih = board.size();
        if (ih == 0) return res;
        iw = board[0].size();
        visit = new bool*[ih];
        for (int i = 0; i < ih; i++) {
            visit[i] = new bool[iw];
            for (int j = 0; j < iw; j++) {
                visit[i][j] = false;
            }
        }

        // build
        for (int i = 0; i < ih; i++) {
            for (int j = 0; j < iw; j++) {
                if (root->children[board[i][j] - 'a'] == NULL) {
                    root->children[board[i][j] - 'a'] = new TrieNode(board[i][j]);
                }
                build_from_pos(j, i, board, root->children[board[i][j] - 'a']);
                init_visit();
            }
        }

        // search
        int ssize = words.size();
        unordered_map<string, bool> word_flag;
        for (int k = 0; k < ssize; k++) {
            if (search(words[k]) && word_flag.find(words[k]) == word_flag.end()) {
                res.push_back(words[k]);
                word_flag.insert(std::pair<string, bool>(words[k], true));
            }
        }

        return res;
    }

    void build_from_pos(int ix, int iy, vector<vector<char> >& board, TrieNode* cur) {
        visit[iy][ix] = true;
        for (int i = 0; i < 4; i++) {
            int nix = ix + w[i];
            int niy = iy + h[i];
            if (nix < 0 || niy < 0 || nix >= iw || niy >= ih || visit[niy][nix]) continue;
            if (cur->children[board[niy][nix] - 'a'] == NULL) {
                cur->children[board[niy][nix] - 'a'] = new TrieNode(board[niy][nix]);
            }
            build_from_pos(nix, niy, board, cur->children[board[niy][nix] - 'a']);
        }
        visit[iy][ix] = false;

    }

    bool search(string word) {
        return search_from_pos(word, root, 0, word.length());
    }

    bool search_from_pos(string word, TrieNode* cur, int pos, int len) {
        if (cur == NULL) return false;
        if (pos >= len) return true;
        if (cur->children[word[pos] - 'a']) {
            return search_from_pos(word, cur->children[word[pos] - 'a'], pos + 1, len);
        } else {
            return false;
        }
    }

    bool** visit;
    TrieNode* root;
    int iw;
    int ih;


    void print_node(TrieNode* cur) {
        for (int i = 0; i < 30; i++) {
            if (cur->children[i]) {
                std::cout << char(i + 'a') << " ";
            }
        }
    }

    void debug() {
        print_node(root->children['e' - 'a']);
        std::cout << std::endl;
        print_node(root->children['e' - 'a']->children['a' - 'a']);
        std::cout << std::endl;


    }
};


class Solution {
public:
    Solution() {
        root = new TrieNode('_');
    }

    void initVisit() {
        for (int i = 0; i < ih; i++) {
            for (int j = 0; j < iw; j++) {
                visit[i][j] = false;
            }
        }
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        ih = board.size();
        if (ih == 0) return res;
        iw = board[0].size();

        visit = new bool*[ih];
        for (int i = 0; i < ih; i++) {
            visit[i] = new bool[iw];
            for (int j = 0; j < iw; j++) {
                visit[i][j] = false;
            }
        }


        //trie build
        for (int i = 0; i < words.size(); i++) {
            addWord(words[i]);
        }
        //get trie longest word;
        //vector<string> triewords = getTrieWord();


        for (int i = 0; i < ih; i++) {
            for (int j = 0; j < iw; j++) {
                searchTrie(board, i, j, root, res, "");
            }
        }
        return res;
    }

    void addWord(string word) {
        int len = word.length();
        TrieNode* cur = root;
        for (int i = 0; i < len; i++) {
            if (cur->children[word[i] - 'a'] == NULL) {
                cur->children[word[i] - 'a'] = new TrieNode(word[i]);
            }
            cur = cur->children[word[i] - 'a'];
        }
        cur->word = true;
    }


    void searchTrie(vector<vector<char> >& board, int i, int j, TrieNode* cur, vector<string>& res, string str) {
        if (i >= ih || i < 0 || j >= iw || j < 0 || visit[i][j] || cur == NULL) return;
        visit[i][j] = true;
        if (cur != root) {
            if (cur->word && !cur->occur) {
                res.push_back(str);
                cur->occur = true;
            }
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + h[k];
            int nj = j + w[k];
            searchTrie(board, ni, nj, cur->children[board[i][j] - 'a'], res, str + board[i][j]);
        }
        cur = cur->children[board[i][j] - 'a'];
        if (cur && cur->word && !cur->occur) {
            res.push_back(str + board[i][j]);
            cur->occur = true;
        }
        visit[i][j] = false;
    }

    int iw;
    int ih;
    bool** visit;
    TrieNode* root;
};

int main(int argc, char* argv[]) {
    vector<vector<char> > board;
    vector<char> tmp;
    tmp.push_back('o');
    tmp.push_back('a');
    tmp.push_back('a');
    tmp.push_back('n');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('e');
    tmp.push_back('t');
    tmp.push_back('a');
    tmp.push_back('e');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('i');
    tmp.push_back('h');
    tmp.push_back('k');
    tmp.push_back('r');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('i');
    tmp.push_back('f');
    tmp.push_back('l');
    tmp.push_back('v');
    board.push_back(tmp);
    tmp.clear();
    vector<string> words;
    words.push_back("oath");
    words.push_back("pea");
    words.push_back("eat");
    words.push_back("rain");

    Solution s;
    vector<string> res = s.findWords(board, words);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    return 0;
}