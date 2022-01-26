#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

const int SIZE = 1000010;
long long fac[SIZE];
long long mod = 1e9 + 7;

ll printNcR(ll n, ll r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = __gcd(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    return p;
}


set<ll>st;
ll ar[200010];
unordered_map<ll,ll>mp;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll ans;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,n;
        ll sum = 0LL, ans = 0LL, x;
        double k;
        mp.clear();
        st.clear();
        sf(n);
        for(i=0;i<n;i++)
        {
            sl(x);
            sum+=x;
            st.insert(x);
            mp[x]++;
        }
        k = (double)sum/double(n);
        int cnt = 0;
        for(auto it:st)
        {
            ar[cnt++]=it;
            if(mp[it]>=2LL)
            {
                double val = it+it;
                val = val/2.0;
                if(abs(val-k)<=eps)
                {
                    ans += printNcR(mp[it],2);
                }
            }
        }


        i = 0;
        j = cnt-1;
        while(i<j)
        {
            double a = ar[i];
            double b = ar[j];
            double avg = (a+b)/2.0;

            if(abs(avg-k)<=eps)
            {
                ans+=(mp[ar[i]]*mp[ar[j]]);
            }
            if(avg>k)
                j--;
            else
                i++;
        }
        pl(ans);
    }

    return 0;
}
