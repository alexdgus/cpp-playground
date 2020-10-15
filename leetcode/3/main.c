#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void rotateIterate(int *nums, int numsSize, int k) {
  if(k < 1 || numsSize < 2) return;
  int *newArray = malloc(numsSize * sizeof(int));
  for (int i = k; i < numsSize; i++) {
    newArray[i] = nums[i - k];
  }
  int j = numsSize - k;
  for (int i = 0; i < k; i++, j++) {
    newArray[i] = nums[j];
  }
  memcpy(nums, newArray, sizeof(int) * numsSize);
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

static void rotateChunk(int *nums, int numsSize, int k) {
  if(k < 1 || numsSize < 2) return;
  int frontSize = numsSize - k;
  int *front = malloc(frontSize * sizeof(int));
  int *back = malloc(k * sizeof(int));
  memcpy(front, nums, (frontSize) * sizeof(int));
  memcpy(back, &nums[frontSize], k * sizeof(int));
  memcpy(nums, back, k * sizeof(int));
  memcpy(&nums[k], front, frontSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 2, 3, 4, 5, 6};
  //rotateIterate(nums, 6, 2);
  rotateChunk(nums, 6, 2);
  int nums2[] = {1, 2, 3, 4, 5, 6, 7};
  //rotateIterate(nums2, 7, 3);
  rotateChunk(nums2, 7, 3);
}
