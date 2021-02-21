#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>

void printVec(std::vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void checkSort(std::vector<int> &vec) {
    for( int i = 0; i < vec.size() - 1; i++) {
        if(vec[i] > vec[i+1]) {
            std::cout << "Unsorted element at index " << i << " and " << i+1 << "\n";
            return;
        }
    }
    std::cout << "Sort successful\n";
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(std::vector<int> &vec, int startIndex, int endIndex) {
    int smaller = startIndex - 1;
    int pivot = vec[endIndex];
    std::cout << "**Partition** startIndex " << startIndex << " endIndex " << endIndex << "\n";
    for(int i = startIndex; i < endIndex; i++) {
        if(vec[i] <= pivot) {
            smaller++;
            swap(&vec[i], &vec[smaller]);
        }
    }
    swap(&vec[smaller + 1], &vec[endIndex]);
    std::cout << "partitionIndex " << smaller + 1 << "\n";
    printVec(vec);
    std::cout << "\n";
    return smaller + 1;
}

void quickSortEx(std::vector<int> &vec, int startIndex, int endIndex) {
    if(endIndex - startIndex >= 1) {
        int partitionIndex = partition(vec, startIndex, endIndex);
        quickSortEx(vec, startIndex, partitionIndex - 1);
        quickSortEx(vec, partitionIndex + 1, endIndex);
    }
}

void quickSort(std::vector<int> &vec) {
    quickSortEx(vec, 0, vec.size() - 1);
}

int main(int argc, char* argv[]) {
    int size = 20;
    std::cout << argv[0] << "\n";
    if(argc > 1) {
        std::string s = argv[1];
        size = std::stoi(s);
    }
    std::vector<int> vec;
    for(int i = 0; i < size; i++) {
        vec.push_back(std::rand() % 100);
    }

    printVec(vec);

    quickSort(vec);

    printVec(vec);
    checkSort(vec);
}