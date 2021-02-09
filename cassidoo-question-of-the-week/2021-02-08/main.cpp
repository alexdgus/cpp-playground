/*
This week’s question:
Implement a ProductList class that has two methods, add(n) (which pushes the
value n to the back of the list) and product(m) (which returns the product of
the last m numbers in the list). David made an awesome template for submitting
your solutions, if you’d like to use it!

Usage:

ProductList p = new ProductList();
p.add(7);         // [7]
p.add(0);         // [7,0]
p.add(2);         // [7,0,2]
p.add(5);         // [7,0,2,5]
p.add(4);         // [7,0,2,5,4]
p.product(3);     // return 40 because 2 * 5 * 4 */

#include <iostream>
#include <vector>

class ProductList {
public:
  void add(int factor) { productList.push_back(factor); }

  int product(int count) {
    int sum = 1;
    for (int i = productList.size() - count; i < productList.size(); i++) {
      sum *= productList[i];
    }
    return sum;
  }

private:
  std::vector<int> productList;
};

int main() {
  ProductList p;
  p.add(7); // [7]
  p.add(0); // [7,0]
  p.add(2); // [7,0,2]
  p.add(5); // [7,0,2,5]
  p.add(4); // [7,0,2,5,4]

  std::cout << p.product(3) << "\n";

  return 0;
}