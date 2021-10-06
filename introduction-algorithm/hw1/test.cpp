#include <iostream>
#include <vector>

int main() {
    // 1, 3 case
    int n = 3;
    std::vector<std::vector<int>> matrix = {{1, 1}, {1, 3}, {3, 1}};

    /*
    // 3, 1, 5, 8 case
    int n = 5;
    std::vector<std::vector<int>> matrix = {{1, 3}, {3, 1}, {1, 5}, {5, 8}, {8, 1}};
    */

    /*
    // 1, 3, 5, 6, 2 case
    int n = 6;
    std::vector<std::vector<int>> matrix = {{1, 1}, {1, 3}, {3, 5}, {5, 6}, {6, 2}, {2, 1}}; 
    */

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for(int s = 1 ; s < n ; s++) {
        for(int i = 0 ; i + s < n ; i++) {
            int j = i + s;
            int maxSum = 0;
            for(int k = i; k < j ; k++) {
                cout << "s : " << s << " i : " << i <<" k : " <<
                int candid = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1]; 
                if(candid > maxSum) {
                    maxSum = candid;
                }
            }
            dp[i][j] = maxSum;
        }
    }
    std::cout << dp[0][n - 1] << "\n";
}