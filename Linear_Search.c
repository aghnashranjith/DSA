#include <stdio.h>

int Linear_Search(int A[], int n, int key)
/* Returns if key is found index at which key is found else -1 is returned */
{
    for(int i = 1; i < n; i++)
    {
        if(key == A[i])
            return i;
    }
    return -1;
}

void main()
{
    int array[10];
    for(int i = 0; i < 10; i++)
        scanf("%d", &array[i]);
    
    int index = Linear_Search(array, 10, 69);      //hehe nice
    if(index != -1)
        printf("\n\n%d %d", index, array[index]);
    else 
        printf("\nnotfound");
}