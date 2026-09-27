#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0) return 0;

    //1.先排序
    qsort(nums, numsSize, sizeof(int), cmp);
    //2.去重

    int k = 1;

    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] != nums[i -1])
        {
            nums[k] = nums[i];
            k++;
        }

    }
    return k;
}




void testRemoveDuplicates(int* nums, int numsSize)
{
    int newSize = removeDuplicates(nums, numsSize);
    printf("New size: %d\n", newSize);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main()
{
    // exam1
    int nums1[] = {1, 2, 2,4, 1,5, 5, 6};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    testRemoveDuplicates(nums1, nums1Size);

    // exam2


    // Boundary test


    return 0;    

}
