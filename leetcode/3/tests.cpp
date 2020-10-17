#include "gtest/gtest.h"
#include "rotate.h"
#include "string.h"

TEST(Rotate, Iterate) { 
    int x[] = { 1, 2, 3, 4, 5, 6 };
    int y[] = { 5, 6, 1, 2, 3, 4 };

    rotateIterate(x, 6, 2);
    ASSERT_TRUE(0 == memcmp(x, y, sizeof(x)));
}

TEST(Rotate, Chunk) { 
    int x[] = { 1, 2, 3, 4, 5, 6 };
    int y[] = { 5, 6, 1, 2, 3, 4 };

    rotateChunk(x, 6, 2);
    ASSERT_TRUE(0 == memcmp(x, y, sizeof(x)));
}

TEST(Rotate, InPlace) { 
    int x[] = { 1, 2, 3, 4, 5, 6 };
    int y[] = { 5, 6, 1, 2, 3, 4 };

    rotateInPlace(x, 6, 2);
    ASSERT_TRUE(0 == memcmp(x, y, sizeof(x)));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
