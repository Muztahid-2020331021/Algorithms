//*The complexity of heap sort is O(N*log(N)) where N is the number of nodes.
#include<bits/stdc++.h>
using namespace std;


void swp(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_top_down(int arr[], int n, int i)
{

    int largest = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;
    if (lc < n && arr[largest] < arr[lc])
        largest = lc;
    if (rc < n && arr[largest] < arr[rc])
        largest = rc;

    if (largest != i)
    {
        swp(&arr[largest], &arr[i]);
        heapify_top_down(arr, n, largest);
    }
}

void heap_sort(int arr[],int n){
    int i;
    //* Making Max-heap
    for(i=n/2-1;i>=0;i--){
        heapify_top_down(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swp(&arr[0],&arr[i]);
        heapify_top_down(arr,i,0);
    }
}




int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i;i<n;i++){
        cin>>arr[i];
    }
    heap_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" \n"[i==n-1];
    }

}

/* 
6
12 11 13 5 6 7 
 */