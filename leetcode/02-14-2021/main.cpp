/* There is an undirected graph with n nodes, where each node is numbered
 * between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
 * array of nodes that node u is adjacent to. More formally, for each v in
 * graph[u], there is an undirected edge between node u and node v.

 * A graph is bipartite if the nodes can be partitioned into two independent
 * sets A and B such that every edge in the graph connects a node in set A and
 * a node in set B.

 * Return true if and only if it is bipartite. */

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  static bool isBipartite(std::vector<std::vector<int>> &graph) {
    if (graph.size() <= 1) {
      return false;
    }

    std::unordered_set<int> setA;
    std::unordered_set<int> setB;
    std::queue<int> q;
    q.push(0);
    setA.insert(0);
    while (!q.empty()) {
      for (auto &val : graph[q.front()]) {
        if (setA.count(q.front())) {
          if (setA.count(val)) {
            return false;
          } else if (!setB.count(val)) {
            setB.insert(val);
            q.push(val);
          }
        } else if (setB.count(q.front())) {
          if (setB.count(val)) {
            return false;
          } else if (!setA.count(val)) {
            setA.insert(val);
            q.push(val);
          }
        }
      }
      q.pop();
      if (q.empty()) {
        for (int i = 0; i < graph.size(); i++) {
          if (graph[i].size() != 0 && !setA.count(i) && !setB.count(i)) {
            setA.insert(i);
            q.push(i);
            break;
          }
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec = {{4}, {}, {4}, {4}, {0, 2, 3}};

  Solution s;
  std::cout << "is bipartite: " << s.isBipartite(vec) << "\n";
}