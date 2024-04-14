#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int i;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    set<int> st;
    for(i=0;i<n;i++){
        auto it = st.lower_bound(v[i]);
        if(it!=st.end()){
            st.erase(it);
        }
        st.insert(v[i]);
    }
    cout<<st.size()<<endl;

}
