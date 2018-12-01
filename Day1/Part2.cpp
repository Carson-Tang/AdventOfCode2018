#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
unordered_map<int,int>f;
int tot,n,a[953],idx;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 953; i++) cin>>a[i];
    f[0]=1;
    while(1){
        tot+=a[idx++];
        if(f.find(tot)!=f.end()){cout<<tot; break;}
        f[tot]=1;
        if(idx==953) idx=0;
    }
    return 0;
}
