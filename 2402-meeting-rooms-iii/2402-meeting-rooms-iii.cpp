#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector <pair <ll,ll> > vp(n , {0,0});
        sort(meetings.begin(), meetings.end());
        for(ll i =0; i<meetings.size();i++){
            ll x=meetings[i][1]-meetings[i][0];
            ll maxm= LLONG_MAX,ind=-1,ind2=-1;
            for(ll j = 0; j<n;j++){
                if(vp[j].first <= meetings[i][0] && ind==-1){
                    ind=j;
                    break;
                }
                if(vp[j].first<maxm){
                    maxm=vp[j].first;
                    ind2=j;
                }
            }
            if(ind!=-1){
                vp[ind].first= meetings[i][1];
                 vp[ind].second++;
            }
            else{
                vp[ind2].first+=x;
                 vp[ind2].second++;
            }
        }
        ll ans=-1,ind = -1;
        for(ll i=0;i<n;i++){
            cout<<vp[i].first<<" "<<vp[i].second<<endl;
            if(vp[i].second > ans){
                ans=vp[i].second ;
                ind=i;
            } 
        }
        return ind;
    }
};