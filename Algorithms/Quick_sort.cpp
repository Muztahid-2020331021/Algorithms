#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low], temp;
    int i = low + 1;
    int j = high;
    do
    {
        while (v[i] <= pivot)
        {
            i++;
        }
        while (v[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    } while (i < j);

    temp = v[low];
    v[low] = v[j];
    v[j] = temp;

    return j;
}

void quicksort(vector<int> &v, int low, int high)
{
    int part_index;
    if(low< high){
        part_index = partition(v, low, high);
        quicksort(v, low, part_index - 1);
        quicksort(v, part_index + 1, high);
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
    quicksort(v, 0, v.size() - 1);
    for (auto bal : v)
    {
        cout << bal << " ";
    }
}