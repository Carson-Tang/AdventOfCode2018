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
int n,indeg[27],cnt;
bool vis[27];
queue<int>q;
vector<int>adj[27],topo;
string s1,s3,s4,s5,s6,s7,s9,s10;
char s2,s8;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    n = 101;
    while(n--){
        cin>>s1>>s2>>s3>>s4>>s5>>s6>>s7>>s8>>s9>>s10;
        adj[(s2-65)].push_back((s8-65));
        indeg[(s8-65)]++;
    }
    while(cnt!=26){
        for(int i = 0; i < 26; i++){
            if(indeg[i]==0&&!vis[i]){
                cout<<(char)(i+65);
                vis[i]=1;
                q.push(i);
                cnt++;
                break;
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                indeg[v]--;
            }
        }
    }
    return 0;
}
