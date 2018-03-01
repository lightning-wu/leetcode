

string longestPalindrome(string s) {
    int len = s.length();
    if (len == 0) return "";
    int **p = new int*[len];
    int max_len = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i < len; i++)
        p[i] = new int[len];
    for (int i = len - 1; i >= 0; i--){
            p[i][i] = 1; 
            if (max_len < 1){
                max_len = 1;
                max_i = i;
                max_j = i;
            }
        for (int j = i + 1; j < len; j++){
            p[i][j] = (s[i] == s[j]);
            if (j >= i + 2)
                p[i][j] &= p[i + 1][j - 1];
            if (p[i][j] && max_len < (j - i + 1)){
                max_len = j - i + 1;
                max_i = i;
                max_j = j;  
            }
        }
    } 
    return s.substr(max_i, max_j - max_i + 1);
}
