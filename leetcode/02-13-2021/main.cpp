/* In an N by N square grid, each cell is either empty (0) or blocked (1).
 * Return the length of the shortest such clear path from top-left to
 * bottom-right. If such a path does not exist, return -1. */
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  const std::vector<std::pair<int, int>> offsets = {
      {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0 || m == 0 || m != n || grid[0][0] != 0 ||
        grid[n - 1][m - 1] != 0) {
      return -1;
    }

    std::queue<std::pair<int, int>> frontier;
    frontier.push({0, 0});
    int step = 0;
    while (!frontier.empty()) {
      step++;
      int size = frontier.size();
      for (int i = 0; i < size; i++) {
        int x = frontier.front().first;
        int y = frontier.front().second;
        if (x == m - 1 && y == n - 1) {
          return step;
        }
        for (auto& offset : offsets) {
          int searchx = x + offset.first;
          int searchy = y + offset.second;
          if (searchx >= 0 && searchx < grid.size() && searchy >= 0 &&
              searchy < grid.size() && grid[searchx][searchy] == 0) {
            frontier.push(std::pair<int, int>(searchx, searchy));
            grid[searchx][searchy] = 1;
          }
        }
        frontier.pop();
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 0, 0},
      {0, 0, 0, 1, 1, 1, 0}, {1, 0, 0, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 0, 1},
      {0, 0, 1, 0, 0, 0, 0}};
  std::cout << "Shortest Path: " << s.shortestPathBinaryMatrix(grid) << "\n";
  return 0;
}