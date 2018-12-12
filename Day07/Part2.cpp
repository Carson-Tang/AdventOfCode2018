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
int n,indeg[27],cnt,work[5],t,task[5];
bool vis[27];
queue<int>q;
vector<int>adj[27];
string s1,s3,s4,s5,s6,s7,s9,s10,ans;
char s2,s8;
bool openwork(){
    for(int i = 0; i < 5; i++){
        if(!work[i]) return true;
    } return false;
}
void givework(int cost){
    for(int i = 0; i < 5; i++){
        if(!work[i]){
            work[i]=cost+60;
            task[i]=cost-1;
            return;
        }
    }
}
void update(){
    for(int i = 0; i < 5; i++){
        if(work[i]){
            work[i]--;
            if(!work[i]){
                cnt++;
                for(int v : adj[task[i]]){
                    indeg[v]--;
                }
                task[i]=0;
            }
        }
    }
}
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
            if(!indeg[i]&&!vis[i]&&openwork()){
                vis[i]=1;
                givework(i+1);
            }
        }
        update();
        t++;
    }
    cout<<t;
    return 0;
}
