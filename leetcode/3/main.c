#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rotate.h"

int main(int argc, char *argv[]) {
  int nums0[] = {1, 2, 3, 4, 5, 6};
  //rotateIterate(nums, 6, 2);
  //rotateChunk(nums, 6, 2);
  rotateInPlace(nums0, 6, 2);
  int nums[] = {1, 2, 3, 4, 5, 6};
  //rotateIterate(nums, 6, 2);
  //rotateChunk(nums, 6, 2);
  rotateInPlace(nums, 6, 4);
  int nums2[] = {1, 2, 3, 4, 5, 6, 7};
  //rotateIterate(nums2, 7, 3);
  //rotateChunk(nums2, 7, 3);
  rotateInPlace(nums2, 7, 3);
  int nums3[] = {1, 2, 3, 4, 5, 6, 7};
  rotateInPlace(nums3, 7, 5);
}
