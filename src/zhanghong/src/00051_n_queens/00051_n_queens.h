#ifndef SRC_ZHANGHONG_SRC_00051_N_QUEENS_H__
#define SRC_ZHANGHONG_SRC_00051_N_QUEENS_H__

#include <vector>
#include <string>

using namespace std;

namespace Solution51 {

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        
        vector<int> ch(n, -1); // chess board that indicates queens' posiontion (coloumn)
        dfs(ch, res, 0);
        
        return res;
    }

private:
    void dfs(vector<int> & ch, vector<vector<string>> & res, int row)
    {
        const int N = ch.size();

        if (N == row) // base case - find a solution
        {
            vector<string> solution;
            for (int i = 0; i < N; i++)
            {
                string s(N, '.');
                for (int j = 0; j < N; j++)
                {
                    if (j == ch[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            res.push_back(solution);
            return;
        }

        for (int j = 0; j < N; j++)
        {
            const bool ok = canPut(ch, row, j);
            if (!ok) continue; // cut
            
            ch[row] = j; // expand 
            dfs(ch, res, row+1);
        }
    }

    bool canPut(const vector<int> & ch, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            /* | */ 
            if (ch[i] == col) return false;
            /* cross */  
            if (abs(i - row) == abs(ch[i] - col)) return false;

        }
        return true;
    }
};

}


#endif