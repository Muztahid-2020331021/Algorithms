#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int mid, int lo, int hi)
{
    int i, j, k;
    vector<int> v1(v.size());
    i = lo;
    j = mid + 1;
    k = lo;
    while (i <= mid && j <= hi)
    {
        if (v[i] <= v[j])
        {
            v1[k] = v[i];
            i++;
            k++;
        }
        else
        {
            v1[k] = v[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        v1[k] = v[i];
        i++;
        k++;
    }
    while (j <= hi)
    {
        v1[k] = v[j];
        j++;
        k++;
    }
    for (i = lo; i <= hi; i++)
    {
        v[i] = v1[i];
    }
}

void merge_sort(vector<int> &v, int lo, int hi)
{
    int mid;
    if (lo < hi)
    {
        mid = (hi + lo) / 2;
        merge_sort(v, lo, mid);
        merge_sort(v, mid + 1, hi);
        merge(v, mid, lo, hi);
    }
}

int main()
{
    int n;
    cin >> n;
    int i;
    vector<int> v;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    merge_sort(v, 0, n - 1);
    for (auto bal : v)
    {
        cout << bal << " ";
    }
}