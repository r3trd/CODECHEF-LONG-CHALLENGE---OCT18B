#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
    int n,m; scanf("%d %d", &n, &m);
    
    char s[n][m];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>s[i][j];
    }
    int mat1[n][m], mat2[n][m];
    
    // matrix starting with 1
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    //cout<<1<<" "<<s[i][j]<<" ";
                    if(s[i][j]!='1')
                        mat1[i][j]=1;
                    else
                        mat1[i][j]=0;
                }
                else
                {
                    //cout<<0<<" "<<s[i][j]<<" ";
                    if(s[i][j]!='0')
                        mat1[i][j]=1;
                    else
                        mat1[i][j]=0;
                }
            }
            else
            {
                if(j%2==0)
                {
                    //cout<<0<<" "<<s[i][j]<<" ";
                    if(s[i][j]!='0')
                        mat1[i][j]=1;
                    else
                        mat1[i][j]=0;
                }
                else
                {
                    //cout<<1<<" "<<s[i][j]<<" ";
                    if(s[i][j]!='1')
                        mat1[i][j]=1;
                    else
                        mat1[i][j]=0;
                }
            }
        }
        //cout<<endl;
    }
    //cout<<endl;
    // matrix starting with 0
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(i%2!=0)
            {
                if(j%2==0)
                {
                    if(s[i][j]!='1')
                        mat2[i][j]=1;
                    else
                        mat2[i][j]=0;
                }
                else
                {
                    if(s[i][j]!='0')
                        mat2[i][j]=1;
                    else
                        mat2[i][j]=0;
                }
            }
            else
            {
                if(j%2!=0)
                {
                    if(s[i][j]!='1')
                        mat2[i][j]=1;
                    else
                        mat2[i][j]=0;
                }
                else
                {
                    if(s[i][j]!='0')
                        mat2[i][j]=1;
                    else
                        mat2[i][j]=0;
                }
            }
        }
    }
    
    int sm1=0, sm2  =0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            sm1 += mat1[i][j];
            sm2 += mat2[i][j];
        }
    }
    
    int flag = 1;
    if(sm1 == 0 || sm2 == 0)
    {
        flag = 0;
        
    }
    
    if(flag==0)
    {
        int q; scanf("%d", &q);
        while(q--)
        {
            ll qi; scanf("%lld", &qi);
            cout<<min(n,m)<<endl;
        }
        return 0;
    }
    // Row Cumulative cost matrix for mat1 and mat2
    int c_mat1[n][m], c_mat2[n][m];
    
    for(int i=0; i<n; i++)
    {
        for(int j = m-1; j>=0; j--)
        {
            if(j==m-1)
            {
                c_mat1[i][j] = mat1[i][j];
                c_mat2[i][j] = mat2[i][j];
            }
            else
            {
                c_mat1[i][j] = c_mat1[i][j+1] + mat1[i][j];
                c_mat2[i][j] = c_mat2[i][j+1] + mat2[i][j];
            }
        }
    }
    // Column Cumulative cost matrix for c_mat1 and c_mat2
    
    int cc_mat1[n][m], cc_mat2[n][m];
    
    for(int j=0; j<m; j++)
    {
        for(int i = n-1; i>=0; i--)
        {
            if(i==n-1)
            {
                cc_mat1[i][j] = c_mat1[i][j];
                cc_mat2[i][j] = c_mat2[i][j];
            }
            else
            {
                cc_mat1[i][j] = cc_mat1[i+1][j] + c_mat1[i][j];
                cc_mat2[i][j] = cc_mat2[i+1][j] + c_mat2[i][j];
            }
        }
    }
    
    int dim = min(n,m);
    std::vector<int> chess[dim+1];
    
    // Cost calculation for each dimension
    for(int i = n-1; i>=1; i--)
    {
        //cout<<i<<endl;
        for(int j = m-1; j>=1; j--)
        {
            //cout<<j<<endl;
            for(int k = min(i+1,j+1); k>=1; k--)
            {
                int temp = cc_mat2[i-k+1][j-k+1];
                if(i+1<n && j+1<m)
                    temp += (cc_mat2[i+1][j+1] - cc_mat2[i-k+1][j+1] - cc_mat2[i+1][j-k+1]);
                else if(i+1<n && j+1>=m)
                    temp = temp - cc_mat2[i+1][j-k+1];
                else if(j+1<m && i+1>=n)
                    temp = temp - cc_mat2[i-k+1][j+1];
                //cout<<i<<" "<<j<<" "<<k<<" "<temp<<endl;
                
                int temp1 = cc_mat1[i-k+1][j-k+1];
                if(i+1<n && j+1<m)
                    temp1 = temp1 + cc_mat1[i+1][j+1] - cc_mat1[i-k+1][j+1] - cc_mat1[i+1][j-k+1];
                else if(i+1<n && j+1>=m)
                    temp1 = temp1 - cc_mat1[i+1][j-k+1];
                else if(j+1<m && i+1>=n)
                    temp1 = temp1 - cc_mat1[i-k+1][j+1];
                    
                //cout<<i<<" "<<j<<" "<<k<<" "<<temp1<<endl;
                chess[k].push_back(temp);
                chess[k].push_back(temp1);    
            }
        }
    }
    
    
    for(int i=1; i<=dim; i++)
    {
        sort(chess[i].begin(), chess[i].end());
        /*cout<<i<<endl;
        for(int j=0; j<chess[i].size(); j++)
            cout<<chess[i][j]<<" ";
        cout<<endl<<endl;*/
    }
    
    ll cost[chess[dim][0]] = { 0 };
    //ll idx = 1;
    for(ll i=0; i<=chess[dim][0]; i++)
    {
        //int fl = 0;
        for(ll idx = 1; idx<=dim; idx++)
        {
            if(i>= chess[idx][0])
            {
                cost[i] = idx;
            }
        }
    }
    
    ll q; scanf("%lld", &q);
    
    while(q--)
    {
        
        ll qi; scanf("%lld", &qi);
        if(qi>=chess[dim][0])
            cout<<cost[chess[dim][0]]<<endl;
        else
            cout<<cost[qi]<<endl;
    }
    
    return 0;
}