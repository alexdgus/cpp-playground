/* Implement FreqStack, a class which simulates the operation of a stack-like
 * data structure.

 * FreqStack has two functions:

 * 1. push(int x), which pushes an integer x onto the stack.
 * 2. pop(), which removes and returns the most frequent element in the stack.

 * If there is a tie for most frequent element, the element closest to the top
 * of the stack is removed and returned. */

class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> freqMap;
    unordered_map<int, stack<int>> freqStackMap;

    FreqStack() : maxFreq(0) {}
    
    void push(int x) {
        int freq = ++freqMap[x];

        if(freq > maxFreq) {
            maxFreq = freqMap[x];
        }
        freqStackMap[freq].push(x);
    }
    
    int pop() {
        int x = freqStackMap[maxFreq].top();
        freqStackMap[maxFreq].pop();
        freqMap[x]--;
        if(freqStackMap[maxFreq].empty()) {
            freqStackMap.erase(maxFreq); //Look up syntax
            maxFreq--;
        }
        return x;
    }
};