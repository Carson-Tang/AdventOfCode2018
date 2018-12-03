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
int n,x,y,x1,y1,cnt,idx;
vector<int>g[1001][1001];
bool f[1288];
string s1,s2,s3,s4;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    n=1287;
    while(n--){
        idx++;
        cin>>s1>>s2>>s3>>s4;
        x = stoi(s3.substr(0,s3.find(",")));
        y = stoi(s3.substr(s3.find(",")+1,s3.find(":")-s3.find(",")-1));
        x1 = stoi(s4.substr(0,s4.find("x")));
        y1 = stoi(s4.substr(s4.find("x")+1,s4.length()-s4.find("x")-1));
        for(int i = x; i < x+x1; i++){
            for(int j = y; j < y+y1; j++){
                g[i][j].push_back(idx);
            }
        }
    }
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            if(g[i][j].size()>1){
                for(int a : g[i][j]) f[a]=1;
            }
        }
    }
    for(int i = 1; i < 1288; i++){
        if(!f[i]) cout<<i;
    }
    return 0;
}
