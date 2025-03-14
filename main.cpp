#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<string>& ds, int n) {
        int dupRow = row;
        int dupCol = col;
        
        while (row >= 0 && col >= 0) {
            if (ds[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0) {
            if (ds[row][col] == 'Q')
                return false;
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (row < n && col >= 0) {
            if (ds[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void findSol(int col, int n, vector<vector<string>>& ans, vector<string>& ds) {
        if (col == n) {
            ans.push_back(ds);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, ds, n)) {
                ds[row][col] = 'Q';
                findSol(col + 1, n, ans, ds);
                ds[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds(n, string(n, '.'));
        findSol(0, n, ans, ds);
        return ans;
    }
};

void printSolution(vector<vector<string>>& ans) {
    for (auto& board : ans) {
        for (auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);

    cout << "\nSolutions for " << n << "-Queens problem:\n\n";
    printSolution(ans);

    return 0;
}
