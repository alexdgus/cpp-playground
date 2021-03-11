#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class CircularBuffer {
    public:
        CircularBuffer(int size);
        ~CircularBuffer();

        int Push(char* data, int size);
        int Pop(char* data, int size);
        void Print();

    private:
        char* mArray = nullptr;
        int mSize;
        int mHead;
        int mCount;
};

CircularBuffer::CircularBuffer(int size) : mSize(size), mHead(0), mCount(0) {
    mArray = (char*)malloc(size);
}

CircularBuffer::~CircularBuffer() {
    free(mArray);
}

int CircularBuffer::Push(char* data, int size) {
    size = std::min(mSize - mCount, size);
    int nextFree = (mHead + mCount) % mSize;
    int writeCount = std::min(mSize - nextFree, size);
    memcpy(&mArray[nextFree], data, writeCount);
    if(writeCount < size) {
        memcpy(mArray, &data[writeCount], size - writeCount);
    }
    mCount += size;
    return size;
}

int CircularBuffer::Pop(char* data, int size) {
    size = std::min(size, mCount);
    int nextFree = (mHead + mCount) % mSize;
    int readCount = std::min(mSize - nextFree, size);
    memcpy(data, &mArray[mHead], readCount);
    memset(&mArray[mHead], 0, readCount);
    if(readCount < size) {
        memcpy(&data[readCount], mArray, size - readCount);
        memset(mArray, 0, size - readCount);
    }
    mHead = (mHead + size) % mSize;
    mCount -= size;
    return size;
}

void CircularBuffer::Print() {
    for(int i = 0; i < mSize; i++) {
        printf("%d:%c ", i, mArray[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    CircularBuffer buffer(12);
    char array[5];
    char array1[] = "abc";
    char array2[] = "def";
    char array3[] = "hijklmno";
    buffer.Push(array1, 3);
    buffer.Print();
    buffer.Push(array2, 3);
    buffer.Print();
    buffer.Pop(array, 5);
    buffer.Print();
    buffer.Push(array3, 8);
    buffer.Print();
    buffer.Push(array3, 8);
    buffer.Print();
}