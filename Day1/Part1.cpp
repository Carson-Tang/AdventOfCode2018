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
int ans,n;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n){
        ans+=n;
    }
    cout<<ans;
    return 0;
}
