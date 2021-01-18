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
    ll a[m];
    for (int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    long long int cntneg=0, cntpos=0, sum=0;
    if(n==1)
    {
        sort(a,a+m);
        if(a[0]>0)cout<<0<<endl;
        else if(a[m-1]<0) cout<<0<<endl;
        else
        {
            for(int i=0;i<m;i++)
            {
                if(a[i]>0){cntneg=i;cntpos=m-i;break;}
            }
            while (cntneg>0 && cntpos>0)
            {
                sum = sum + cntneg+cntpos -1;
                cntneg --;
                cntpos --;
            }
            cout<<sum<<endl;
        }
    }

}



int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int k;
    cin>>k;
    while(k--)
    {
        solve();
    }
    return 0;
}
