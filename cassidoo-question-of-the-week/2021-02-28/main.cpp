/* Given a room size, and the square footage a paint can can cover, return how
 * many cans of paint you need to buy to paint a room. Assume the room has four
 * walls. If you’d like to expand this, you can add doors, windows, or any other
 * room features that might make the problem interesting to solve. */

#include <cmath>
#include <iostream>

struct room {
    int length;
    int width;
    int height;
};

static int numberOfCans(room r, int coverage) {
    int totalArea = 2 * r.length * r.height + 2 * r.width * r.height;
    return ceil((double)totalArea / coverage);
}

int main() {
    room r = {12, 10, 9};
    std::cout << "Number of cans: " << numberOfCans(r, 396) << "\n";
}