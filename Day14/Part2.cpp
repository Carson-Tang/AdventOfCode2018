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
int sum,idx1,idx2,cnt;
string ans,buf,n;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n="909441";
    ans="37";
    idx1=0; idx2=1;
    while(1){
        sum = (ans.at(idx1)-48)+(ans.at(idx2)-48);
        buf = to_string(sum);
        ans+=buf;
        idx1 = (idx1+1+((int)ans.at(idx1)-48))%ans.length();
        idx2 = (idx2+1+((int)ans.at(idx2)-48))%ans.length();
        if(ans.length()>6){
                if(ans.length()%10000==0) cout<<ans.length()<<"\n";
                if(ans.substr(ans.length()-7,6)==n){
                    cout<<ans.length()-7;
                    break;
                }
                if(ans.substr(ans.length()-6,6)==n){
                    cout<<ans.length()-6;
                    break;
                }
        }
        cnt++;
    }
    return 0;
}
