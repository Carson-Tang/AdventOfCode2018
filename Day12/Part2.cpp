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
string s,s2,s3,cur,curr;
int n,g; ll ans;
char a[1001];
unordered_map<string,char>mp;
void upd(int idx){
    curr=cur.substr(idx-2,5);
    a[idx]=mp[curr];
}
int calc(){
    int temp = 0;
    for(int i = 0; i < 1001; i++){
        if(a[i]=='#'){
            temp+=i-400;
        }
    } return temp;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n=32;
    cin>>s>>s2>>s3;
    for(int i = 0; i < 1001; i++) a[i]='.';
    for(int i = 400; i < 500; i++) a[i]=s3.at(i-400);
    while(n--){
        cin>>s>>s2>>s3;
        mp[s]=s3.at(0);
    }
    g=200;
    while(g--){
        cur = "";
        for(int i = 0; i < 1001; i++) cur+=a[i];
        for(int i = 2; i < 998; i++){
            upd(i);
        }
        if(g==1)ans-=calc();
        if(g==0)ans+=calc();
    }
    cout<<ans*(50000000000-200)+calc();
    return 0;
}
