static int maxProfit(int *prices, int pricesSize) {
  int totalProfit = 0;
  int buyIndex = 0;

  if (pricesSize == 0)
    return 0;

  for (int sellIndex = 1; sellIndex < pricesSize; sellIndex++) {
    if (prices[sellIndex] > prices[buyIndex]) {
      totalProfit += prices[sellIndex] - prices[buyIndex];
    }
    buyIndex = sellIndex;
  }

  return totalProfit;
}

int main() {
  int prices[] = {1, 2, 4, 3, 5, 3, 2, 1};
  int length = sizeof(prices) / sizeof(prices[0]);
  maxProfit(prices, length);
}
