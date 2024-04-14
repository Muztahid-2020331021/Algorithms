#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BinarySearch_with_Array(ll to_find, ll n, vector<ll> &v);
ll LowerBound(ll element, ll n, vector<ll> &v);
ll UpperBound(ll element, ll n, vector<ll> &v);


int main()
{
    int n;
    cin>>n;
    int i;
    vector<ll> v;

    for(i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    BinarySearch_with_Array(6,n,v);
    
}

void BinarySearch_with_Array(ll to_find, ll n, vector<ll> &v){
    int lo=0, hi=n-1;
    int mid;
    while(hi-lo>1){
        int mid= (hi+lo)/2;
        if(v[mid] < to_find){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]==to_find){
        cout<<lo<<endl;
    }
    else if(v[hi]==to_find){
        cout<<hi<<endl;
    }
    else{
        cout<<"Not Found\n";
    }
}

ll LowerBound(ll element, ll n, vector<ll> &v){
    int lo=0, hi=n-1;
    int mid;
    while(hi - lo> 1){
        mid=(hi+lo)/2;
        if(v[mid]<element){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]>=element){
        return lo;
    }
    if(v[hi]>=element){
        return hi;
    }
    return -1;
}

ll UpperBound(ll element, ll n, vector<ll> &v){
    int lo=0, hi=n-1;
    int mid;
    while(hi - lo> 1){
        mid=(hi+lo)/2;
        if(v[mid]<=element){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]>element){
        return lo;
    }
    if(v[hi]>element){
        return hi;
    }
    return -1;
}