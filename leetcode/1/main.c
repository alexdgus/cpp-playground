#include <stdio.h>

static int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return 0;
    }
    int currentIndex = 0;
    int nextIndex = 1;
    while(nextIndex < numsSize)
    {
        if(nums[currentIndex] != nums[nextIndex])
        {
            nums[++currentIndex] = nums[nextIndex];
        }
        nextIndex++;
    }
    return currentIndex + 1;
}

int main(int argc, char* argv[])
{
    int length = 4;
    int nums[] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4};
    length = sizeof(nums)/sizeof(nums[0]);
    for(int i = 0; i < length; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n");
    length = removeDuplicates(nums, length);
    for(int i = 0; i < length; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n");
    return 1;
}

