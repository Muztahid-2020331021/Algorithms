#include <bits/stdc++.h>
using namespace std;

void sele(vector<int> &v)
{
    int indexofmin, i, j,temp;
    for (i = 0; i < v.size() - 1; i++)
    {
        indexofmin = i;
        for (j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[indexofmin])
            {
                indexofmin = j;
            }
        }
        
        temp=v[i];
        v[i]=v[indexofmin];
        v[indexofmin]=temp;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sele(v);
    for(auto bal: v){
        cout<<bal<<" ";
    }
}