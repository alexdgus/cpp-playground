/* This week’s question:
You are given a snapshot of a queue of stocks that have changing prices coming
in from a stream. Remove the outdated stocks from the queue.

Example:

$ snapshot = [
  { sym: ‘GME’, cost: 280 },
  { sym: ‘PYPL’, cost: 234 },
  { sym: ‘AMZN’, cost: 3206 },
  { sym: ‘AMZN’, cost: 3213 },
  { sym: ‘GME’, cost: 325 }
]
$ stockQueue(snapshot)
$ [{ sym: ‘PYPL’, cost: 234 },
   { sym: ‘AMZN’, cost: 3213 },
   { sym: ‘GME’, cost: 325 }] */

#include <iostream>
#include <list>
#include <map>
#include <string>

struct stonk {
  std::string ticker;
  int price;
};

static std::list<stonk> snapshot({{"GME", 280},
                                  {"PYPL", 234},
                                  {"AMZN", 3206},
                                  {"AMZN", 3213},
                                  {"GME", 325}});

int main() {
  static std::list<stonk> stockQueue;
  static std::map<std::string, int> stockMap;
  for (auto it = snapshot.rbegin(); it != snapshot.rend(); ++it) {
    if (stockMap.find(it->ticker) == stockMap.end()) {
      stockMap.insert({it->ticker, it->price});
      stockQueue.push_front(*it);
    }
  }

  for (auto it : stockQueue) {
    std::cout << it.ticker << " " << it.price << "\n";
  }
}