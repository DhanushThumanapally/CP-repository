/*author @dhanush*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define pb push_back
#define all(x) x.begin(), x.end()
#define se second
#define fi first
ll MOD = 1e9 + 7;
const ll N=100001;
ll spf[N];
void  mainsolve()
{
  for(int i=1;i<N;i++)
  {
    spf[i]=i;
  }
  for(ll i=2;i*i<N;i++)
  {
    if(spf[i]==i)
    {
       for(ll j=i*i;j<N;j+=i)
       {
         spf[j]=i;
       }
    }
  }
}
void peace()
{
  
  ll n;
  cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  
  map<ll,ll>mp2;
  for(int i=0;i<n;i++)
  {
    ll xx=arr[i];
    while(xx>1)
    {
      ll x=spf[xx];
      mp2[x]++;
      xx/=x;
    }
    

  }
  map<ll,ll>mp1;
  set<ll>s;
  for(int i=0;i<n;i++)
  {
    ll xx=arr[i];
    while(xx>1)
    {
      ll x=spf[xx];
      mp1[x]++;
      
      s.insert(x);
      xx/=x;
      if(mp1[x]==mp2[x])
      {
        s.erase(x);
      }

    }

  
    if(s.size()==0)
    {
      cout<<i+1<<endl;
      return;
    }
    

  }

}
int main()
{
  boost;
  ll t;
   mainsolve();
  t = 1;

  cin >> t;

  while (t--)
    peace();
}
