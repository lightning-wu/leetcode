
 vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    bool* visit = new bool[n];
    vector<string> sol;
    string str = "";
    for (int i = 0; i < n; i++){
        str += ".";
    }
    for (int i = 0; i < n; i++){
        sol.push_back(str);
    }
    step(0, n, visit, sol, res);
    return res;
 }

 bool step(int s, int n, bool* visit, vector<string>& sol, vector<vector<string> >& res){
    if (s == n){
        res.push_back(sol);
        return true;
    } 
    for (int c = 0; c < n; c++){
        if (visit[c]) continue;
        visit[c] = true;
        sol[s][c] = 'Q';
        step(s + 1, n, visit, sol, res);
        visit[c] = false;
        sol[s][c] = '.';
    }
 }
