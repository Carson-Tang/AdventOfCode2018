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
int n,y,m,d,h,mn,id,guard[4000][60],ind,minute,hour,mx,best,bestid,besttime,T;
string s,s2,bf,bf1,bf2,bf3,bf4;
struct upd{
    int y,m,d,h,mn,idx;
    bool operator<(const upd &a) const{
        if(y!=a.y) return y<a.y;
        if(m!=a.m) return m<a.m;
        if(d!=a.d) return d<a.d;
        if(h!=a.h) return h<a.h;
        if(mn!=a.mn) return mn<a.mn;
        return idx>a.idx;
    }
};
vector<upd>update;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    n = 1170;
    while(n--){
        cin>>s;
        y = stoi(s.substr(1,4));
        m = stoi(s.substr(6,2));
        d = stoi(s.substr(9,2));
        cin>>s2;
        h = stoi(s2.substr(0,2));
        mn = stoi(s2.substr(3,2));
        cin>>bf;
        if(bf=="wakes"){
            cin>>bf2;
            update.push_back({y,m,d,h,mn,-1});
        } else if (bf=="falls"){
            cin>>bf2;
            update.push_back({y,m,d,h,mn,-2});
        } else {
            cin>>bf2>>bf3>>bf4;
            id = stoi(bf2.substr(1,bf2.length()-1));
            update.push_back({y,m,d,h,mn,id});
        }
    }
    sort(update.begin(),update.end());
    for(upd a : update){
        if(a.idx>0){
            ind = a.idx;
        } else if(a.idx==-2){
            hour = a.h;
            minute = a.mn;
        } else {
            for(int i = minute; i < a.mn; i++){
                guard[ind][i]++;
            }
        }
    }
    for(int i = 0; i < 4000; i++){
        mx = 0;
        for(int j = 0; j < 60; j++){
            mx += guard[i][j];
        }
        if(mx>best){
            best=mx;
            bestid=i;
        }
    }
    for(int i = 0; i < 60; i++){
        if(guard[bestid][i]>besttime){
            T=i;
            besttime=guard[bestid][i];
        }
    }
    cout<<bestid*T;
    return 0;
}
