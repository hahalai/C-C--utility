#include <stdio.h>
#include <stdlib.h>
#include "PrintArray.h"

int BubbleSort(int aNumbers[], unsigned int uNumberArraySize)
{
    if (!aNumbers || 2 > uNumberArraySize)
    {
        return 1;
    }
    unsigned int i = 0;
    unsigned int j = 0;
    int nTmp = 0;

    for (i = 0; i < uNumberArraySize; ++i)
    {
        for (j = uNumberArraySize - 1; j > i; --j)
        {
            if (aNumbers[j] < aNumbers[j-1])
            {
                nTmp = aNumbers[j];
                aNumbers[j] = aNumbers[j-1];
                aNumbers[j-1] = nTmp;
            }
        }
    }
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
    BubbleSort(pArray, nArraySize);
    PrintArray(pArray, nArraySize, "Array after sort");

    return 0;
}
