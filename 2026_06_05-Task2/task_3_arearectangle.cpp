//task 3 area rectangle

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<vector<int>> &mat) {
    int n = mat.size(); //row
    int m = mat[0].size(); //column

    vector<vector<int>> memo(n , vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                continue;
            }


            memo[i][j] = (j == 0) ? 1 : memo[i][j - 1] + 1;

            int width = memo[i][j];

            for (int k = i; k >= 0; k--) {
                width = min(width, memo[k][j]);
                int area = width * (i - k + 1);
                ans = max(ans, area);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 0}
    };

    cout << maxArea(mat) << endl; // 6

    return 0;
}