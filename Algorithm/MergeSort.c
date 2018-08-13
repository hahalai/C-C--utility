#include <stdio.h>
#include <stdlib.h>

#include "PrintArray.h"

int MergeSort(int aNumbers[], unsigned int uLeftPos, \
        unsigned int uMiddlePos, unsigned int uRightPos)
{
    if (!aNumbers || !(uLeftPos <= uMiddlePos && uMiddlePos <= uRightPos))
    {
        return 1;
    }

    unsigned int uLeftArraySize = uMiddlePos - uLeftPos + 1;
    unsigned int uRightArraySize = uRightPos - uMiddlePos;
    int *pLeftArray = (int *)malloc(uLeftArraySize * sizeof(int));
    int *pRightArray = (int *)malloc(uRightArraySize * sizeof(int));
    if (!pLeftArray || !pRightArray)
    {
        printf ("malloc left or right array failed.");
        return 1;
    }

    unsigned int i = 0;
    unsigned int j = 0;
    for (i = 0; i <= uLeftArraySize; ++i)
    {
        pLeftArray[i] = aNumbers[uLeftPos+i];
    }

    for (j = 0; j <= uRightArraySize; ++j)
    {
        pRightArray[j] = aNumbers[uMiddlePos+1+j];
    }

    //PrintArray(pLeftArray, uLeftArraySize, "Left array sort");
    //PrintArray(pRightArray, uRightArraySize, "Right array");
    unsigned int k = 0;
    i = 0;
    j = 0;

    for (k = uLeftPos; k <= uRightPos; ++k)
    {
        if (i == uLeftArraySize)
        {
            aNumbers[k] = pRightArray[j++];
            continue;
        }
        else if (j == uRightArraySize)
        {
            aNumbers[k] = pLeftArray[i++];
            continue;
        }

        if (pLeftArray[i] <= pRightArray[j])
        {
            aNumbers[k] = pLeftArray[i++];
        }
        else
        {
            aNumbers[k] = pRightArray[j++];
        }
        //PrintArray(aNumbers+uLeftPos, (uRightPos - uLeftPos + 1), "*****array");
    }

    if (pLeftArray)
    {
        free(pLeftArray);
    }

    if (pRightArray)
    {
        free(pRightArray);
    }

    return 0;
}

int SortSubArray(int aNumbers[], unsigned int uLeftPos, unsigned int uRightPos)
{
    if (uLeftPos < uRightPos)
    {
        unsigned int uMiddlePos = (uRightPos + uLeftPos) / 2;
        SortSubArray(aNumbers, uLeftPos, uMiddlePos);
        SortSubArray(aNumbers, uMiddlePos + 1, uRightPos);
        MergeSort(aNumbers, uLeftPos, uMiddlePos, uRightPos);
    }
    return 0;
}

int SortArray(int aNumbers[], unsigned int uNumbersArraySize)
{
    SortSubArray(aNumbers, 0, uNumbersArraySize-1);
    return 0;
}

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        printf("Usage:%s array_size.\n", argv[0]);
        return 1;
    }

    unsigned int i = 0;
    int nArraySize = atoi(argv[1]);

    if (0 >= nArraySize)
    {
        printf("array_size must be greater than 0.\n");
        return 1;
    }

    int *pArray = (int *)malloc(nArraySize * sizeof(int));

    if (!pArray)
    {
        printf("malloc array failed.\n");
        return 1;
    }

    printf("Please input array:\n");
    while (i < nArraySize)
    {
        scanf("%d", pArray + i);
        ++i;
    }

    PrintArray(pArray, nArraySize, "Array before sort");
    SortArray(pArray, nArraySize);
    PrintArray(pArray, nArraySize, "Array after sort");

    if (pArray)
    {
        free(pArray);
    }
    return 0;
}
