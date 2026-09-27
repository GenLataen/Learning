#include <stdio.h>


void swap (int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

/* 哨兵划分 */
int partition (int nums[], int left, int right)
{
    int i = left, j = right;
    
    while (i < j)
    {
        // 从右往左，寻找首个比基数小的数
        while(i < j && nums[left] <= nums[j]) j--;
        // 从左往右，寻找首个比基数大的数
        while(i < j && nums[left] >= nums[i]) i++;
        // 交换两个元素
        swap(nums , i, j); 
    }
    // 交换基数到分界线
    swap (nums , left, i);
    return i;
}

/* 快速排序 */
void quickSort(int nums[], int left, int right)
{
    if(left >= right){
        return;
    }
    /* 哨兵划分*/
    int pivot = partition(nums, left, right);
    /* 递归左右数组*/
    quickSort(nums, left, pivot-1);
    quickSort(nums, pivot+1, right);
}


int main()
{
    int nums[] = {2, 4, 1, 0, 3, 5};
    quickSort(nums, 0, 5 );
    for(int i = 0; i< 6; i++){
        printf("%2d", nums[i]);
    }

}
