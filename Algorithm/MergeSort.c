#include <stdio.h>
#include <stdlib.h>

#include "PrintArray.h"

int MergeSort(int aResult[], unsigned int uResultArraySize, \
        int aLeft[], unsigned int uLeftArraySize, \
        int aRight[], unsigned int uRightArraySize)
{
    if (!aResult || !aLeft || !aRight \
            || (uResultArraySize != uLeftArraySize + uRightArraySize))
    {
        return 1;
    }

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    for (k = 0; k < uResultArraySize; ++k)
    {
        if (i == uLeftArraySize)
        {
            aResult[k] = aRight[j];
            ++j;
            continue;
        }
        else if (j == uRightArraySize)
        {
            aResult[k] = aLeft[i];
            ++i;
            continue;
        }

        if (aLeft[i] <= aRight[j])
        {
            aResult[k] = aLeft[i];
            ++i;
        }
        else
        {
            aResult[k] = aRight[j];
            ++j;
        }
    }

    return 0;
}


int main(int argc, char *argv[])
{
    if (3 != argc)
    {
        printf("Usage:%s array_a_size array_b_size.\n", argv[0]);
        return 1;
    }

    unsigned int i = 0;
    unsigned int j = 0;
    int nLeftArraySize = atoi(argv[1]);
    int nRightArraySize = atoi(argv[2]);
    unsigned int uResultArraySize = 0;

    if (0 >= nLeftArraySize || 0 >= nRightArraySize)
    {
        printf("array_a_size or array_b_size must be greater than 0.\n");
        return 1;
    }

    uResultArraySize = nLeftArraySize + nRightArraySize;
    int *pLeftArray = (int *)malloc(nLeftArraySize * sizeof(int));
    int *pRighArray = (int *)malloc(nRightArraySize * sizeof(int));
    int *pResultArray = (int *)malloc(uResultArraySize * sizeof(int));

    if (!pLeftArray || !pRighArray || !pResultArray)
    {
        printf("malloc array_a, array_b or array_result failed.\n");
        return 1;
    }

    printf("Please input array a by asc:\n");
    while (i < nLeftArraySize)
    {
        scanf("%d", pLeftArray + i);
        pResultArray[i] = pLeftArray[i];
        ++i;
    }
    printf("Please input array b by asc:\n");
    while (j < nRightArraySize)
    {
        scanf("%d", pRighArray + j);
        pResultArray[nLeftArraySize+j] = pRighArray[j];
        ++j;
    }

    PrintArray(pLeftArray, nLeftArraySize, "LeftArray");
    PrintArray(pRighArray, nRightArraySize, "RightArray");
    PrintArray(pResultArray, uResultArraySize, "ResultArray before sort");
    MergeSort(pResultArray, uResultArraySize, pLeftArray, nLeftArraySize, pRighArray, nRightArraySize);
    PrintArray(pResultArray, uResultArraySize, "ResultArray after sort");

    return 0;
}
