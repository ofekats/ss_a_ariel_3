#include <stdio.h>

#define ARR_LEN 50

/**
 * this function move i numbers to the right in the pointer she got
 * @param arr -int pointer (to an array)
 * @param i -int number
*/
void shift_element(int* arr, int i)
{
    int t1 = *(arr);
    int t2 = *(arr+1);
    for(int k=0; k<i; k++)
    {
        *(arr+1) = t1;
        t1 = t2;
        t2 = *(arr+2);
        arr++;
    }
         
}

/**
 * this function sort the arr by insertion sort
 * (used the function shift_element())
 * @param arr -int pointer (to an array)
 * @param len -int size of arr
*/
void insertion_sort(int* arr , int len)
{
    int num = 0;
    int count = 0;
    arr++;
    for(int i=1; i<len; i++)
    {
        count = 0;
        num = *(arr);
        int * p = (arr-1);
        for(int j=0; j<i; j++)
        {
            if(num <  *p)
            {
                count ++; 
            }
            p = p-1;
        }
        //use fun shift_element if num smaller then the numbers before in the arr
        if(count)
        {
            shift_element((arr-count),count);
        }
        *(arr-count) = num;
        arr++;
    }
}


int main()
{
    int arr [ARR_LEN] = {0};
    //get 50 numbers from user 
    for(int i = 0; i < ARR_LEN; i++)
    {
        scanf("%d", (arr+i));
    }

    insertion_sort(arr, ARR_LEN);
    
    //print arr after insertion_sort
    for(int i=0; i < ARR_LEN ; i++)
    {
        printf("%d", *(arr+i));
        if(i != (ARR_LEN-1))
        {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
