#include<bits/stdc++.h>
using namespace std;

struct Job
{
    char ID;
    int  Deadline;
    int  Profit;
};

bool cmp(Job a, Job b){
    return a.Profit>b.Profit;
}

void JobSequence(Job arr[], int n){
    sort(arr,arr+n,cmp);

    vector<int> result(n);
    vector<bool> slot(n,false);

    int i,j;

    for(i=0;i<n;i++){
        for(j=min(n,arr[i].Deadline)-1;j>=0;j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    for(i=0;i<n;i++){
        if(slot[i]){
            cout<<arr[result[i]].ID<<" ";
        }
    }
    cout<<endl;
}

int main(){
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    int N = sizeof(arr)/sizeof(arr[0]);
    JobSequence(arr,N);

}
