#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rotate.h"

void rotateIterate(int *nums, int numsSize, int k) {
  k = k % numsSize;
  if(k < 1 || numsSize < 2 || k == numsSize) return;
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
  k = k % numsSize;
  if(k < 1 || numsSize < 2 || k == numsSize) return;
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
  k = k % numsSize;
  printf("k: %d\n", k);
  printf("numsSize: %d\n", numsSize);
  if(k < 1 || numsSize < 2 || k == numsSize) return;
  reverse(nums, 0, k-1);
  reverse(nums, k, numsSize - 1);
  for(int x = 0; x < numsSize; x++)
  {
    printf("%d, ", nums[x]);
  }
  printf("\n");
  int i = 0;
  int j = numsSize - 1;
  int revIndex = (k < numsSize - k) ? k : numsSize - k;
  while(i < j)
  {
    swap(nums, i, j);
    i++;
    j--;
  }
  for(int x = 0; x < numsSize; x++)
  {
    printf("%d, ", nums[x]);
  }
  printf("\n");
}
