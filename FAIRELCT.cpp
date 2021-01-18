/*
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=1e9+7;
#define eps 1e-7
#define vpi vector<pair<int,int>>
#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define vvi vector<vector<int>>
ll powmod(ll x,ll y){ll t; for(t=1;y;y>>=1,x=x*x%mod) if(y&1) t=t*x%mod; return t;}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
void smask(int pos,int &i){ i=i^(1<<pos); }
void clmask(int pos,int &i){ i=i&~(1<<pos); }
bool chmask(int pos,int i){return i&(1<<pos);}
double cordist(pair<double,double> a,pair<double,double> b)
{return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));}



//ll dp[60];
//int posx[10];
//int posy[10];
//int price[30];
//int dx[]={-1,0,1,0};
//int dy[]={0,1,0,-1};
//char board[26][26];



int n,m,q,r;
vvi islands;
pi dp[5002];
int vis[5002];

pi safeside(int i)
{
    if(i==n)return {1,1};
    if(dp[i]!=make_pair(-1,-1))return dp[i];
    pi temp={0,0};
    //cout<<i<<endl;
    for(int l=0;l<islands[i].size();l++)
    {
        pi t=safeside(islands[i][l]);
        temp.first+=(1+t.first);
        temp.second+=t.second;
    }
    return dp[i]=temp;
}

void solve()
{
    cin>>n>>m;
    int john[n];
    int jack[m];
    int tempx=0,tempy=0;
    for(int i=0;i<n;i++){
       cin>>john[i];
       tempx+=john[i];
    }
    for(int i=0;i<m;i++){
       cin>>jack[i];
       tempy+=jack[i];
    }
    if(tempx>tempy){
       cout<<"0"<<endl;
       return;
    }
    sort(john,john+n);
    sort(jack,jack+m);
    int count=0;
    int j=m-1;
    for(int i=0;i<n;i++){
       tempx=tempx-john[i];
       tempy=tempy-jack[j];
       tempx=tempx+jack[j];
       tempy=tempy+john[i];
       count++;
       j--;
       if(tempx>tempy || j<0){
           break;
       }
    }
    if(tempx>tempy){
       cout<<count<<endl;
    }else{
       cout<<"-1"<<endl;
    }

}



int main()
{
    /*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/

    int k;
    cin>>k;
    while(k--)
    {
        solve();
    }
    return 0;
}
