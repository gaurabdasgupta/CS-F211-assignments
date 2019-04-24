#include <bits/stdc++.h>
using namespace std;
#define ll long long int
     
class cmp
{
  public:
            bool operator()(pair<ll,pair<ll,ll> >a,pair<ll,pair<ll,ll> >b)
            {
                ll pa1=a.first;
                pair<ll,ll> pa2=a.second;
                ll pb1=b.first;
                pair<ll,ll> pb2=b.second;
                if(pa1>pb1)
                return false;
                else if(pa1<pb1)
                return true;
                else
                {
                    if(pa2.first>pb2.first)
                    return true;
                    else
                    return false;
                }
            }
};
     
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    priority_queue<pair<ll,pair<ll,ll> > ,vector<pair<ll,pair<ll,ll> > >,cmp> pq;
    map<ll,ll> mp;
    pq.push(make_pair(n,make_pair(1,n)));
    pair<ll,pair<ll,ll> > p;
    string s;
    cin>>s;
    for(ll i=0;i<k;i++)
    {
        p=pq.top();
        ll p1=p.first;
        //cout<<p1<<' ';
        pair<ll,ll> p2=p.second;
        //cout<<p2.first<<' '<<p2.second<<'\n';
        if(p1%2==1)
        {
            ll mid=(p2.first+p2.second)/2;
            mp.insert(make_pair(mid,(i+1)));
            pq.pop();
            ll len=p1/2;
            pq.push(make_pair(len,make_pair(p2.first,mid-1)));
            pq.push(make_pair(len,make_pair(mid+1,p2.second)));
        }
        else
        {
            ll mid;
            if(s[i]=='L')
            mid=(p2.first+p2.second)/2;
            else if(s[i]=='R')
            mid=(p2.first+p2.second)/2+1;
            mp.insert(make_pair(mid,(i+1)));
            pq.pop();
            pq.push(make_pair((mid-p2.first),make_pair(p2.first,mid-1)));
            pq.push(make_pair((p2.second-mid),make_pair(mid+1,p2.second)));
        }
    }
    ll q,x;
    cin>>q;
    map<ll,ll>::iterator itr;
    while(q--)
    {
        cin>>x;
        itr=mp.find(x);
        if(itr==mp.end())
        cout<<"-1\n";
        else
        cout<<itr->second<<'\n';
    }
    
return 0;
}