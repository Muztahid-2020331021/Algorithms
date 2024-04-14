#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int i, int j, int init, int neu, vector<vector<int>> &image)
{
    int n = image.size(), m = image[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (init != image[i][j])
        return;

    image[i][j]=neu;

    dfs(i - 1, j, init, neu, image);
    dfs(i, j - 1, init, neu, image);
    dfs(i + 1, j, init, neu, image);
    dfs(i, j + 1, init, neu, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int init = image[sr][sc];
    if(init != color)
        dfs(sr,sc,init,color,image);
    
    return image;
}

int main()
{
}