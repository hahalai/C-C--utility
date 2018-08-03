#include "PrintArray.h"

void PrintArray(int aNums[], unsigned int uArrayLen, const char *pArrayName)
{
    unsigned int i = 0;
    printf("array %s as follow:\n", pArrayName);
    for (i = 0; i < uArrayLen; ++i)
    {   
        printf("%d ", aNums[i]);
    }   
    printf("\n");
}
