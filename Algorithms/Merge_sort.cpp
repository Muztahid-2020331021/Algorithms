#include<bits/stdc++.h>
using namespace std;

int arr[100005], tmp[100005];

void merge(int l, int r){
    int mid = (l + r) / 2;
    int i1 = l, i2 = mid + 1, j = l;
    while(i1 <= mid and i2 <= r){
        if(arr[i1] < arr[i2]){
            tmp[j] = arr[i1];
            i1++;
        }
        else{
            tmp[j] = arr[i2];
            i2++;
        }
        j++;
    }

    while(i1 <= mid){
        tmp[j] = arr[i1];
        j++, i1++; 
    }

    while(i2 <= r){
        tmp[j] = arr[i2];
        j++, i2++;
    }

    for(int i = l; i <= r; i++){
        arr[i] = tmp[i];
    }
}

void mergesort(int l, int r){
    if(l == r) return;

    //divide
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);

    //conquer
    merge(l, r);
}

int main(){
    int n;
    cin>> n;
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }
    mergesort(0, n - 1);
    for(int i = 0; i < n; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
}