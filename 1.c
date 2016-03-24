#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *ret = (int *)malloc(sizeof(int)*2);
    for (i=0; i<numsSize; i++){
        for (j=i+1; j<numsSize; j++){
            if (target == *(nums+i) + *(nums+j)){
                if(i != j){
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
    }
    return NULL;
}

