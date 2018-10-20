#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int moredigits(ll num)
{
    int count = 0;
    while(num)
    {
        ++count;
        if(count==2)
            break;
        num/=10;
    }
    if(count == 2)
        return 1;
    return 0;
}

ll digit_sum(ll num, ll *count)
{
    ll sum = 0;
    if(moredigits(num)==0)
        return num;
    ++(*count);
    while(num)
    {
        sum += (num%10);
        num /= 10;
    }
    return digit_sum(sum,count);
}
ll digit_sum1(ll num)
{
    ll sum = 0;
    if(moredigits(num)==0)
        return num;
    while(num)
    {
        sum += (num%10);
        num /= 10;
    }
    return sum;
}

int main()
{
    int t = 0; scanf("%d", &t);
    
    while(t--)
    {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        
        vector < pair<ll, ll> > sums,sum1;
        
        for(ll i=0; i<9; i++)
        {
            ll count = 0;
            ll temp_n = n + i*k;
            ll d_n = digit_sum(temp_n, &count);
            sums.push_back(make_pair(d_n,count+i));
            ll counter = 0;
    
            while(temp_n)
            {
                ++counter;
                temp_n = digit_sum1(temp_n);
                for(ll j = 1; j<9; j++)
                {
                    ll c=0;
                    ll t = digit_sum(temp_n + j*k, &c);
                    sum1.push_back(make_pair(t, i+c+counter+j));
                }
                ll cc =0;
                if(digit_sum(n+i*k, &cc) == temp_n)
                    break;
            }
        }    
        
        sort(sums.begin(), sums.end());
        sort(sum1.begin(), sum1.end());
        
        if(sum1[0].second <= sums[0].second)
            cout<<sum1[0].first<<" "<<sum1[0].second<<endl;
        else
            cout<<sums[0].first<<" "<<sums[0].second<<endl;
        /*
        cout<<endl;
        for(int i=0; i<9; i++)
            cout<<sums[i].first<<" "<<sums[i].second<<endl;
        cout<<endl;
        for(int i=0; i<sum1.size(); i++)
            cout<<sum1[i].first<<" "<<sum1[i].second<<endl;
        */ 
    }
    
    return 0;
}