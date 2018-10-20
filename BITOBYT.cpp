#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int t = 0; scanf("%d", &t);
    
    while(t--)
    {
        ll n = 0;
        scanf("%lld", &n);
        
        ll pow_2 = n/26;
        n = n - 26*pow_2;
        //cout<<n<<endl;
        ll n_bits = 1;
        ll n_nibs = 0;
        ll n_bytes = 0;
        //cout<<n << " "<<pow_2<<endl;
        if(n)
            n_bits = pow(2, pow_2);
        if(n==0 && pow_2!=0)
        {
            n_bytes = pow(2, pow_2-1);
            n_bits=0;
        }
        
        if(n-10>0)
        {
            n_bytes = n_bits;
            n_bits = 0;
            n-=10;
        }
        else if(n-2>0)
        {
            n_nibs = n_bits;
            n_bits = 0;
        }
          
        cout<<n_bits<<" "<<n_nibs<<" "<<n_bytes<<endl;
    }
    
    return 0;
}