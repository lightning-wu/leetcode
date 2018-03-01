

bool exist(vector<vector<char> >& board, string word) {
    if (board.size() == 0) return false;
    int n = board.size();
    int m = board[0].size();
    int **visit = new int*[n];
    for (int i = 0; i < n; i++){
        visit[i] = new int[m];
    } 
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            bool b = dfs(i, j, n, m, borad, word, 0, visit);
            if (b) return b;
        }
    }
    return false;
}

bool dfs(int x, int y, int n, int m, vector<vector<char> >& board, string& word, int cur, int** visit){
    if (cur >= word.length()) return true;
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (visit[x][y] == 1 || board[x][y] != word[cur]) return false;
    visit[x][y] = 1;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    for (int i = 0; i < 4; i++){
        bool b = dfs(x + dx[i], y + dy[i], n, m, board, word, cur + 1, visit);
        if (b) return true;
    }
    visit[x][y] = 0; 
    return false;
}
