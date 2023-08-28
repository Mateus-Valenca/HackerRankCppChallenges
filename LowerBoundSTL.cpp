#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    std::sort (v.begin(), v.end());
    int n_queries;
    cin>>n_queries;
    int q[n_queries];
    for(int i=0;i<n_queries;i++){
        cin>>q[i];
    }
    std::vector<int>::iterator low;
    for(int i=0;i<n_queries;i++){
        low=std::lower_bound (v.begin(), v.end(), q[i]);
        if(*low!=q[i]){
            cout<<"No"<<" ";
        } else{cout<<"Yes"<<" ";}
        cout<<(low- v.begin()+1)<<endl;
    }
    return 0;
}
