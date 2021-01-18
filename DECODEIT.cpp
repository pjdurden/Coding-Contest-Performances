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



int alphab(int num){
    int temp, b=1, d=0;
    while(num>0){
        temp = num%10;
        d += temp*b;
        num/=10;
        b*=2;
    }
    return d;
}
int main() {
	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif*/
	int t;
	cin>>t;
	string cpystring[16] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"};
	while(t--){
	    int N;
	    cin>>N;
	    string S, strtmp;
	    int temp;
	    cin>>S;
	    for(int i=0;i<N;i+=4){
	        strtmp = S.substr(i,4);
	        temp = stoi(strtmp);
	        int pos  = alphab(temp);
	        cout<<cpystring[pos];
	    }
	    cout<<endl;
	}
	return 0;
}