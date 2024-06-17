#include <vector>
#include <iostream>
#include <algorithm>

// 0-1背包，二维数组解法
void solve2d(int num, int bagSpace) {
    std::vector<int> weight(num, 0);
    std::vector<int> value(num, 0);
    for (int i = 0; i < num; i++) {
      std::cin >> weight[i];
    }
    for (int i = 0; i < num; i++) {
      std::cin >> value[i];
    }
    // dp数组含义：
    // num个物品，bagSpace+1个空间，dp[i][j]代表行李箱空间为j的情况下,从下标为[0, i]的物品里面任意取,能达到的最大价值
    std::vector<std::vector<int>> dp(num, std::vector<int>(bagSpace + 1, 0));
    // 初始化, 因为需要用到dp[i - 1]的值
    // j < weight[0]已在上方被初始化为0，物品体积大于背包空间，放不下
    // j >= weight[0]的值就初始化为value[0]，物品体积可以放下
    for (int i = weight[0]; i <= bagSpace; i++) {
        dp[0][i] = value[0];
    }
    for (int i = 1; i < num; i++) {
        for (int j = 0; j <= bagSpace; j++) {
          // 如果装不下这个物品,那么就继承dp[i - 1][j]的值
          if (j < weight[i]) {
            dp[i][j] = dp[i-1][j];
          } else {
            // 如果能装下,就将值更新为 不装这个物品的最大值 和 装这个物品的最大值 中的 最大值
            // 装这个物品的最大值由容量为j - weight[i]的包任意放入序号为[0, i - 1]的最大值 + 该物品的价值构成
            dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
          }
        }
    }
    std::cout << "res : " << dp[num-1][bagSpace] << std::endl;
}

// 使用滚动数组优化空间使用
void solve1d(int num, int bagSpace) {
    std::vector<int> weight(num, 0);
    std::vector<int> value(num, 0);
    for (int i = 0; i < num; i++) {
      std::cin >> weight[i];
    }
    for (int i = 0; i < num; i++) {
      std::cin >> value[i];
    }
    std::vector<int> dp(bagSpace + 1, 0);
    // 先遍历物品，再遍历背包
    for (int i = 0; i < num; i++) {
        // 内层循环从 N 空间逐渐减少到当前研究材料所占空间
        // dp[j]再赋值前整个dp数组都是i-1的物品下每个背包空间的利益最大化物品选取
        for (int j = bagSpace; j >= weight[i]; j--) {
          dp[j] = std::max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    std::cout << "res : " << dp[bagSpace] << std::endl;
}

// 物品数量：6 背包容量：1
// 2 2 3 1 5 2
// 2 3 1 5 4 3
int main() {
    int n, bagSpace;
    while(std::cin >> n >> bagSpace) {
        solve1d(n, bagSpace);
    }
    return 0;
}