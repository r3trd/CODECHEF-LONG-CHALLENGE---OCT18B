#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int t = 0; scanf("%d", &t);
    
    while(t--)
    {
        ll p1, p2, k;
        scanf("%lld %lld %lld", &p1,&p2,&k);
        
        ll score_sum = p1 + p2;
        ll serves = score_sum/k;
        
        if(serves&1)
            cout<<"COOK"<<endl;
        else
            cout<<"CHEF"<<endl;
    }
    
    return 0;
}