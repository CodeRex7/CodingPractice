#include <bits/stdc++.h>

using namespace std;

int findRegion(vector< vector<int> > matrix, vector< vector<bool> > &visited, int row, int col,int n, int m) {
        if (row >= n || col >= m) return 0;
        if (row < 0 || col < 0) return 0;
        int count = 0;
        if (visited[row][col]) return 0;
        visited[row][col] = true;
        if (matrix[row][col] == 0) {
            return 0;
        }
        count = 1;
        count += findRegion(matrix, visited, row + 1, col,n,m);
        count += findRegion(matrix, visited, row, col + 1,n,m);
        count += findRegion(matrix, visited, row + 1, col + 1,n,m);
        count += findRegion(matrix, visited, row - 1, col,n,m);
        count += findRegion(matrix, visited, row, col - 1,n,m);
        count += findRegion(matrix, visited, row - 1, col - 1,n,m);
        count += findRegion(matrix, visited, row - 1, col + 1,n,m);
        count += findRegion(matrix, visited, row + 1, col - 1,n,m);
        return count;
    }


int getBiggestRegion(int n, int m, vector< vector<int> > matrix) {
        vector <vector <bool> > visited(n);
        for(int i=0;i<n;i++){
            visited[i].resize(m);
        }
        int bigRegion = 0;
        int size = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == 1 && !visited[i][j]) {
                    size = findRegion(matrix, visited, i, j,n,m);
                    bigRegion = max(bigRegion, size);
                }
            }
        }
        return bigRegion;
    }
    



int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;
    

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int a=getBiggestRegion(n,m,grid);
    cout<<a<<endl;
    return 0;
}
