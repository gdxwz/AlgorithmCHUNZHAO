/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int* ret =(int*)malloc(sizeof(int)*arr1Size);
    int mask[1000] = { 0 };
    int k = 0;
    int k1 , k2;
    int temp;
    for(int i = 0; i < arr2Size; i++){
       for(int j = 0; j < arr1Size; j++){
            if(arr1[j] == arr2[i]){
                ret[k++] = arr1[j];
                mask[j] = 1;
            }
       } 
    }
    k1 = k;
    for(int i = 0; i < arr1Size; i++){
        if(mask[i] == 0){
           ret[k++] = arr1[i];
        }
    }
    k2 = k;
    for(int i = k1; i < k2 -1 ; i++){
        for(int j = i + 1; j < k2 ; j++){
            if(ret[i] > ret[j]){
                temp = ret[i];
                ret[i] = ret[j];
                ret[j] = temp;
            }
        }
    }
    *returnSize = arr1Size;
    return ret;
}