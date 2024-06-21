// 牛客网 HJ16 购物单
#include <iostream>
#include <vector>
using namespace std;

//1000 5
//800 2 0
//400 5 1 （主件是800块的那个）
//300 5 1（主件是800块的那个）
//400 3 0
//500 2 0

// 分组背包问题
int main() {
    // M是物品件数，N是总钱数
    int M, N;
    cin >> N >> M;
    // 因为总钱数是10的倍数，因此除以10降低空间/时间复杂度
    N /= 10;
    // 为什么用M + 1，因为题目所给的q表示主件附件的含义是从1下标开始，这里表示方便
    vector<vector<int>> prices(M + 1, vector<int>(3, 0)); // 每个物品对应的1主最多2副件
    vector<vector<int>> priority(M + 1, vector<int>(3, 0));// 每个物品对应的重要程度(价值*重要性)
    for (int i = 1; i <= M; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        v /= 10, p *= v;
        if (q == 0) {
            //主件
            prices[i][0] = v, priority[i][0] = p;
        } else if (prices[q][1] == 0) {
            // 附件1
            prices[q][1] = v, priority[q][1] = p;
        } else {
            // 附件2
            prices[q][2] = v, priority[q][2] = p;
        }
    }
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    // 先遍历物品
    for (int i = 1; i <= M; i++) {
        // 再遍历每个背包空间
        for (int j = 0; j <= N; j++) {
            int p0 = prices[i][0], q0 = priority[i][0];
            int p1 = prices[i][1], q1 = priority[i][1];
            int p2 = prices[i][2], q2 = priority[i][2];
            // 只装主件
            if (j >= p0) {
              dp[i][j] = max(dp[i-1][j], dp[i-1][j-p0] + q0);
            } else {
              dp[i][j] = dp[i-1][j];
            }
            // 装主件+附件1
            if (j >= (p0 + p1)) {
              dp[i][j] = max(dp[i][j], dp[i-1][j-p0-p1] + q0 + q1);
            }
            // 装主件+附件2
            if (j >= (p0 + p2)) {
              dp[i][j] = max(dp[i][j], dp[i-1][j-p0-p2] + q0 + q2);
            }
            // 装主件+附件1+附件2
            if (j >= (p0 + p1 + p2)) {
              dp[i][j] = max(dp[i][j], dp[i-1][j-p0-p1-p2] + q0 + q1 + q2);
            }
        }
    }
    cout << dp[M][N] * 10 << endl;
}