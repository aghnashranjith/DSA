/* This is the code to minheap.
    A minheap is a binary tree in which :
    Each level except possibly the last is full 
    Last level is filled from left to right
    The ordering of key values is such that for each subtree, the key at the root of the subtree is smaller than or equal to the keys
    in its left and right subtrees
    
    In this code I have implemented the heap using an array */

#include <stdio.h>

int heap_size;

int swap(int var1, int var2)
{
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

int left_child_index(int index)
{
    return 2*index + 1;
}

int left_child(int H[], int index)
{
    return H[left_child_index(index)];
}

int right_child_index(int index)
{
    return 2*index + 2;
}

int right_child(int H[], int index)
{
    return H[right_child_index(index)];
}

int parent_index(int index)
{
    return (index - 1)/2;
}

// Heaps are usually used to implement priority queues

/* Helper functions:
    Siftup and MinHeapify */

int findMin(int H[])
{
    return H[0];
}

void siftUp(int H[], int posn)
{
    while((posn>0)&&(H[posn]<H[parent_index(posn)]))
    {
        swap(H[posn], H[parent_index(posn)]);
        posn = parent_index(posn);
    }
}

int minHeapify(int H[], int posn)
/* MinHeapify here assumes that the left and right subtrees at posn are heaps as well. 
   When minHeapify is done the subtree rooted at posn will become a heap                 */
{
    //Using the property that all leaf nodes have an index greater than heapsize/2 we eliminate the cases were minHeapify was called on a leaf node
    if (posn >= heap_size/2)
        return;
    
    //Now we try and find the least value among H[posn], leftchild at posn and rightchild at posn so as to 
    // correctly place that value in H[posn]
    int index_of_smallest;
    if(left_child(H, posn) < H[posn])
        index_of_smallest = left_child_index(posn);
    if((right_child_index(posn) <= heap_size - 1)&&(right_child(H, posn) < H[index_of_smallest] ))
        index_of_smallest = right_child_index(posn);

    // and now we call 
    if(index_of_smallest == posn)
        return posn;
    else
    {
        swap(H[posn], H[index_of_smallest]);
        minHeapify(H, index_of_smallest);
    }
    
}

/* Standard operations and their standard time complexity of min heap are
    FindMin     theta(1)
    Insert 
    Decreasekey, given an index
    ExtractMin(Deletemin) - worst case time complexity of all these operations are theta(height of the tree) = theta(logn)
    Buildheap, given an array of keys   theta(n) */