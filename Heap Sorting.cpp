#include<stdio.h>
#include<math.h>
const int n=10;

void swap(int*a,int*b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
 void Build_Heap(int heap[n],int n)
{
    int parr,j;
    for(int i=0;i<=n-1;i++)
    {
        printf("Enter the value: ");
        scanf("%d",&heap[i]);
        if(i!=0)
        {
            j=i;

            parr=floor((j-1)/2);
            while(heap[parr]<heap[j])
            {

                swap(&heap[parr],&heap[j]);
                j=parr;
                parr=floor(((j-1)/2));
            }
        }
    }
}
void Heapify(int heap[n],int i,int index)
{
    int left,parr,right,maxIndex;
    if(i>0)
    {
        parr=floor((i-1)/2);
        right=parr*2 +2;
        left=2*parr+1;
        if(right==index)
            maxIndex=i;
/* This condition means if our right is equal to  out of Heapify range INDEX than we will consider left as max index*/
        else
        {
           if(heap[left]>heap[right])
             maxIndex=left;
           else
             maxIndex=right;
        }
        if(heap[maxIndex]>heap[parr])
            swap(&heap[parr],&heap[maxIndex]);
        i=i-2; //i=i-1 IS ALSO CORRECT BUT THIS SAVES TIME THAT IS WHY i DID THIS
        Heapify(heap,i,index);
    }
    else
        return;
}

void HeapSort(int arr[n],int n)
{
    for(int index=n-1;index>=0;index--)
    {
        int i=index-1; //This doesn't include swapped element that is why we passed this as index in Heapify function.
        swap(&arr[0],&arr[index]);
        Heapify(arr,i,index);

    }

}
int main()
{
    int arr[n];
    Build_Heap(arr,n);
    printf("\nThe max Heap:\n");
    for(int i=0;i<=n-1;i++)
    {
       printf("\n%d",arr[i]);
    }
     printf("\nSORTED HEAP: ");
     HeapSort(arr,n);
     for(int i=0;i<=n-1;i++)
    {
       printf("\n%d",arr[i]);
    }


}
