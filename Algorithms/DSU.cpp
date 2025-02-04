#include<bits/stdc++.h>
using namespace std;

class UnionFind{
    private:
        vector<int> par, sz;

    public:
        UnionFind(int n){
            par = vector<int> (n);
            iota(par.begin(), par.end(), 0);
            sz = vector<int> (n, 1);
        }

        int find(int v){
            if(par[v] == v) return v;
            return par[v] = find(par[v]);
        }

        bool isconnected(int a, int b){
            a = find(a);
            b = find(b);
            return a == b;
        }

        void join(int a, int b){
            a = find(a);
            b = find(b);
            if(a != b){
                if(sz[a] < sz[b]){
                    swap(a, b);
                }
                par[b] = a;
                sz[a] += sz[b];
            }
        }
};
