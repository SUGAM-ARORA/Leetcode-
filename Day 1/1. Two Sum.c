int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *res = calloc((*returnSize=2), sizeof(int));

    for (int i=0; i<numsSize; i++)
    {
        int x = target - nums[i];
        for (int j=i+1; j<numsSize; j++)
        {
            if (x == nums[j])
            {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return 0;
}
