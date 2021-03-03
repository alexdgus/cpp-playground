#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
    std::vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);

    std::vector<int>::iterator iter;

    for(iter = x.begin(); iter!= x.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << "\n";
}