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
int n;
string s, st[250];
bool check(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.length(); i++){
        if(a.at(i)!=b.at(i)) cnt++;
    }
    return cnt==1;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(n<250) cin>>st[n++];
    for(int i = 0; i < 250; i++){
        for(int j = 0; j < 250; j++){
            if(check(st[i],st[j])){
                for(int k = 0; k < st[i].length(); k++){
                    if(st[i].at(k)==st[j].at(k)){
                        cout<<st[i].at(k);
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
