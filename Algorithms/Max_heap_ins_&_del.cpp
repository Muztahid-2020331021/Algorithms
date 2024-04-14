#include <bits/stdc++.h>
using namespace std;
//*0-Based indexing
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
        swap(arr[largest], arr[i]);
        heapify_top_down(arr, n, largest);
    }
}

void heapify_bottom_up(int arr[], int n, int i){
    int par=(i-1)/2;
    if(i>0){
        if(arr[par]<arr[i]){
            swap(arr[par],arr[i]);
            heapify_bottom_up(arr,n,par);
        }
    }
}

void del_root(int arr[], int &n){
    int last_element=arr[n-1];
    arr[0]=last_element;
    n--;
    heapify_top_down(arr, n, 0);
}

void ins_node(int arr[], int& n, int key){
    n++;
    arr[n-1]=key;
    heapify_bottom_up(arr,n,n-1);
}