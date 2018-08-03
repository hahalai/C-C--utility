#include <stdio.h>
#include <stdlib.h>

void PrintArray(int aNums[], unsigned int uArrayLen)
{
    unsigned int i = 0;
    printf("Current array as follow:\n");
    for (i = 0; i < uArrayLen; ++i)
    {
        printf("%d ", aNums[i]);
    }
    printf("\n");
}

void insertion_sort(int aNums[], unsigned int uArrayLen)
{
    int i = 0;
    unsigned int j = 0;
    int nCurrNum = 0;

    /* 从[j, n-1]的元素开始，与[1, j-1]已排好序的数组做比较。
    ** 如果在[1，j-1]中找到第i个元素不比第j个元素大，则将[1, j-1]中第i个元素
    ** 后的所有元素均后移一位，将第j个元素插入到第i+1个元素的位置。
    ** 反之，则将[1，j-1]中所有元素后移一位，第j个元素插入到第1个元素的位置。
    */
    for (j = 1; j < uArrayLen; ++j)
    {
        nCurrNum = aNums[j];
        i = j - 1;
        while (0 <= i && aNums[i] > nCurrNum)
        {
            aNums[i+1] = aNums[i];
            --i;
            //PrintArray(aNums, uArrayLen);
        }
        aNums[i+1] = nCurrNum;
        //PrintArray(aNums, uArrayLen);
    }
}

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        printf("Usage:%s array_size\n", argv[0]);
        return 1;
    }
    int nArrayLen = atoi(argv[1]);
    if (0 >= nArrayLen)
    {
        printf("array_size must be greater than 0.\n ");
        return 1;
    }
    int *pNumbers = (int *)malloc(nArrayLen * sizeof(int));

    if (!pNumbers)
    {
        printf("malloc array failed.\n");
        return 1;
    }

    unsigned int i = 0;
    printf("Please input %d numbers:\n", nArrayLen);
    while (i < nArrayLen)
    {
        scanf("%d", &pNumbers[i]);
        ++i;
    }

    //int aNumbers[6] = {5, 2, 4, 6, 1, 3};
    //unsigned int uArrayLen = sizeof(aNumbers)/sizeof(int);
    PrintArray(pNumbers, nArrayLen);
    insertion_sort(pNumbers, nArrayLen);
    PrintArray(pNumbers, nArrayLen);
    if (pNumbers)
    {
        free(pNumbers);
    }
    return 0;
}
