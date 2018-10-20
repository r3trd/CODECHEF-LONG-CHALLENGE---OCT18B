#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,m; scanf("%lld %lld", &n, &m);
    vector <ll> a(n),b(n),cost(n);
    
    for(ll i=0; i<n; i++)
        scanf("%lld", &a[i]);
    for(ll i=0; i<n; i++)
        scanf("%lld", &b[i]);
    for(ll i=0; i<n; i++)
        cost[i]=a[i]*b[i];
    
    ll high = *max_element(cost.begin(), cost.end());
    ll low = 0;
    ll mid;
    vector <ll> res;
    while(low<high)
    {
        mid = low + (high - low)/2;
        ll t_ballons = 0;
        for(ll i=0; i<n; i++)
        {
            if(cost[i]>mid)
            {
                if((cost[i]-mid)%b[i] == 0)
                    t_ballons += (cost[i]-mid)/b[i];
                else
                    t_ballons += ((cost[i]-mid)/b[i] + 1);
            }
        }
        if(t_ballons <= m)
            high = mid;
        else
            low = mid + 1;
    }
    cout<<low<<endl;
    
    return 0;
}