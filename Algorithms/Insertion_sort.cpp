#include<bits/stdc++.h>
using namespace std;


void insertion(vector<int> &v){
    int key, j,i;
    //Loop for passes 
    for(i=0;i<v.size();i++){
        key=v[i];
        j=i-1;
        //Loop for each pass
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }

}

int main(){

    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    insertion(v);
    for(auto bal: v){
        cout<<bal<<" ";
    }

}