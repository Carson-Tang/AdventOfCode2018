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
int n,a,b;
string s;
bool check(int num, string t){
    int c[27];
    memset(c,0,sizeof c);
    for(int i = 0; i < t.length(); i++) c[t.at(i)-97]++;
    for(int i = 0; i < 27; i++) if(c[i]==num) return true;
    return false;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n = 250;
    while(n--){
        cin>>s;
        if(check(2,s))a++;
        if(check(3,s))b++;
    }
    cout<<a*b;
    return 0;
}
