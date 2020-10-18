#include "gtest/gtest.h"
#include "rotate.h"
#include "string.h"

static void commonTests(void (*rotateFunc)(int* nums, int numsSize, int k))
{
    int length = 0;

    rotateFunc(NULL, 0, 6);
    rotateFunc(NULL, 5, 6);

    int a1[] = { 1, 2, 3, 4, 5, 6 };
    int a2[] = { 1, 2, 3, 4, 5, 6 };
    length = sizeof(a1)/sizeof(a1[0]);
    rotateFunc(a1, length, 0);
    ASSERT_TRUE(0 == memcmp(a1, a2, sizeof(a2)));
    rotateFunc(a1, length, length);
    ASSERT_TRUE(0 == memcmp(a1, a2, sizeof(a2)));

    int a3[] = { 1, 2, 3, 4, 5, 6 };
    int a4[] = { 5, 6, 1, 2, 3, 4 };
    rotateFunc(a3, 6, 2);
    length = sizeof(a3)/sizeof(a3[0]);
    ASSERT_TRUE(0 == memcmp(a3, a4, sizeof(a4)));

    int a5[] = { 1, 2, 3, 4, 5, 6 };
    int a6[] = { 3, 4, 5, 6, 1, 2 };
    length = sizeof(a5)/sizeof(a5[0]);
    rotateFunc(a5, length, 4);
    ASSERT_TRUE(0 == memcmp(a5, a6, sizeof(a6)));

    int a7[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int a8[] = { 11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    length = sizeof(a7)/sizeof(a7[0]);
    rotateFunc(a7, length, 1);
    ASSERT_TRUE(0 == memcmp(a7, a8, sizeof(a8)));

    int a9[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int a10[] = { 8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7 };
    length = sizeof(a9)/sizeof(a9[0]);
    rotateFunc(a9, length, 4);
    ASSERT_TRUE(0 == memcmp(a9, a10, sizeof(a10)));

    int a11[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int a12[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1 };
    length = sizeof(a11)/sizeof(a11[0]);
    rotateFunc(a11, length, length - 1);
    ASSERT_TRUE(0 == memcmp(a11, a12, sizeof(a12)));
}

TEST(Rotate, Iterate) { 
    commonTests(rotateIterate);
}

TEST(Rotate, Chunk) { 
    commonTests(rotateChunk);
}

TEST(Rotate, InPlace) { 
    commonTests(rotateInPlace);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
