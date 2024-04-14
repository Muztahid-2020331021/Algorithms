#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int d = 29;

void search(string txt, string pat, map<char,int> &hashMap){
    int t=0,p=0,h=1,i,j;
    int n=txt.length();
    int m=pat.length();

    for(i=1;i<=m-1;i++){
        h=(h*d)%mod;
    }
    

    for(i=0;i<m;i++){
        p=(p*d+hashMap[pat[i]])%mod;
        t=(t*d+hashMap[txt[i]])%mod;
    }

    for(i=0;i<n-m+1;i++){
        if(t==p){
            for(j=0;j<m;j++){
                if(pat[j]!=txt[i+j]){
                    break;
                }
            }

            if(j==m){
                cout<<"Pattern matched at index "<<i<<endl;
            }
        }

        if(i<n-m){
            t=(d*(t-hashMap[txt[i]]*h)+hashMap[txt[i+m]])%mod;
            if(t<0)
                t+=d;
        }
    }
}

int main(){
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    map<char,int> hashMap;
    int i;
    char ch='A';
    for(i=3;i<=28;i++){
        hashMap[ch]=i;
        ch++;
    }
    search(txt,pat,hashMap);
    
}