/* Given n non-negative integers a1, a2, ..., an , where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of the line i is at (i, ai) and (i, 0). Find two lines, which, together with
 * the x-axis forms a container, such that the container contains the most
 * water. */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        while(leftIndex < rightIndex) {
            int y = min(height[leftIndex], height[rightIndex]);
            int x = rightIndex - leftIndex;
            maxA = max(maxA, x * y);
            while(height[leftIndex] <= y && leftIndex < rightIndex) {leftIndex++;}
            while(height[rightIndex] <= y && leftIndex < rightIndex) {rightIndex--;}
        }
        return maxA;
    }
};