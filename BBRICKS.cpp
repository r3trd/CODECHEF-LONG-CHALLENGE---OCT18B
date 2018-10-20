#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1e9 + 7;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
    x = x % p; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}

/*ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
}

ll nCr(ll n, ll r, ll p) 
{ 
    if (r==0) 
        return 1; 
    
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return ((fac[n]* modInverse(fac[r], p) % p) * (modInverse(fac[n-r], p) % p)) % p; 
}*/ 

ll ncr(ll n, ll r, ll p)
{
    ll num =1, den = 1; 
    for(ll i=0; i<r; i++)
    {
        num = (num * (n - i)) % p; 
        den = (den * (i + 1)) % p; 
    }
    return (num * power(den, p - 2, p)) % p ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=0; cin>>t;
    
    while(t--)
    {
        ll n, k; cin>>n>>k;
        ll result = 0;
        //cout<<n<<" "<<k<<"\n";
        for(ll i=1; i<=k; i++)
        {
            
            ll p = power(2,i,mod);
            ll n1 = ncr(k-1, i-1, mod);
            ll n2 = 0;
            if(n-k+1 >=i)
                n2 = ncr(n-k+1, i, mod);
            /*cout<<p<<" "<<n1<<" "<<n2<<"\n";
            
            cout<<n-k+1<<"\n";*/
            ll temp = ((n1%mod)*(n2%mod))%mod;
            temp = ((p%mod)*(temp%mod))%mod;
            
            result = ((result%mod) + (temp%mod))%mod;
        }
        cout<<result<<"\n";
    }
    
    return 0;
}