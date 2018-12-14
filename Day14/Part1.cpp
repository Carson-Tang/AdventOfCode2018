#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
typedef pair<ll,int>lli;
typedef pair<ii,int>piii;
int n,sum,idx1,idx2;
string ans,buf;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n=909441;
    ans="37";
    idx1=0; idx2=1;
    while(ans.length()<=n+10){
        sum = (ans.at(idx1)-48)+(ans.at(idx2)-48);
        buf = to_string(sum);
        ans+=buf;
        idx1 = (idx1+1+((int)ans.at(idx1)-48))%ans.length();
        idx2 = (idx2+1+((int)ans.at(idx2)-48))%ans.length();
    }
    cout<<ans.substr(n,10);
    return 0;
}
