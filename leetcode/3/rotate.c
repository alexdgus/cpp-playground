#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rotate.h"

void rotateIterate(int *nums, int numsSize, int k) {
  if(!nums || k < 1 || numsSize < 2) return;
  k = k % numsSize;
  if(k == 0) return;
  int *newArray = (int*)malloc(numsSize * sizeof(int));
  for (int i = k; i < numsSize; i++) {
    newArray[i] = nums[i - k];
  }
  int j = numsSize - k;
  for (int i = 0; i < k; i++, j++) {
    newArray[i] = nums[j];
  }
  memcpy(nums, newArray, sizeof(int) * numsSize);
}

void rotateChunk(int *nums, int numsSize, int k) {
  if(!nums || k < 1 || numsSize < 2) return;
  k = k % numsSize;
  if(k == 0) return;
  int frontSize = numsSize - k;
  int *front = (int*)malloc(frontSize * sizeof(int));
  int *back = (int*)malloc(k * sizeof(int));
  memcpy(front, nums, (frontSize) * sizeof(int));
  memcpy(back, &nums[frontSize], k * sizeof(int));
  memcpy(nums, back, k * sizeof(int));
  memcpy(&nums[k], front, frontSize * sizeof(int));
  free(front);
  free(back);
}

static void swap(int *nums, int i1, int i2) {
  int temp = nums[i1];
  nums[i1] = nums[i2];
  nums[i2] = temp;
}

static void reverse(int *nums, int si, int ei) {
while(si < ei)
  {
    swap(nums, si, ei);
    si++;
    ei--;
  }
}

void rotateInPlace(int *nums, int numsSize, int k) {
  if(!nums || k < 1 || numsSize < 2) return;
  k = k % numsSize;
  if(k == 0) return;
  reverse(nums, 0, k-1);
  reverse(nums, k, numsSize - 1);
  int chunk1Size = (k * 2) % numsSize;
  reverse(nums, 0, chunk1Size - 1);
  reverse(nums, chunk1Size, numsSize - 1);
}
