#include <vector>

using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    int row = grid.size();
    if (row == 0) return 0;
    int col = grid[0].size();
    int** sum = new int*[row];
    for (int i = 0; i < row; i++){
        sum[i] = new int[col];
    }
    
    sum[0][0] = grid[0][0];
    for (int i = 1; i < row; i++){
        sum[i][0] = sum[i - 1][0] + grid[i][0];
    } 
    for (int i = 1; i < col; i++){
        sum[0][i] = sum[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < row; i++){
        for (int j = 1; j < col; j++){
            sum[i][j] = grid[i][j];
            sum[i][j] += ((sum[i - 1][j] > sum[i][j - 1]) ? sum[i][j - 1] : sum[i - 1][j]);
        }
    }
    return sum[row - 1][col - 1];
}
