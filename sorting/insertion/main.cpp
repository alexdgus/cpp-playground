#include <iostream>
#include <vector>
#include <limits>

void InsertionSort(std::vector<int> &vec) {
    std::vector<int>::iterator insertionPoint = vec.begin();
    std::vector<int>::iterator iter = vec.begin();

    for(int i = 0; i < vec.size(); i++) {
        int min = std::numeric_limits<int>::max();
        std::vector<int>::iterator minLocation = iter;
        for(iter = insertionPoint; iter != vec.end(); iter++) {
            if(*iter < min) {
                min = *iter;
                minLocation = iter;
            }
        }
        int temp = *insertionPoint;
        *insertionPoint = *minLocation;
        *minLocation = temp;
        insertionPoint++;
        iter = insertionPoint;
    }
}

int main() {
    std::vector<int> vec = {100, 200, 99, 56, 12};
    InsertionSort(vec);
    for(auto &val : vec) {
        std::cout << val << ", ";
    }
    std::cout << "\n";
    return 0;
}