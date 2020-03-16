#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        struct pp{
            int dis, wid, bid;
        };
        struct cmp{
            inline bool operator ()(const pp &pp1, const pp &pp2){
                if(pp1.dis == pp2.dis){
                    if(pp1.wid == pp2.wid) return pp1.bid < pp2.bid;
                    return pp1.wid < pp2.wid;
                }
                return pp1.dis < pp2.dis;
            }
        };
        vector<pp> v;
        int l1 = workers.size(), l2 = bikes.size();
        for (int i = 0; i < l1; ++i){
            for (int j = 0; j < l2; ++j){
                pp p;
                p.wid = i, p.bid = j, 
                p.dis = abs(workers[i][0] - bikes[i][0]) + abs(workers[i][1] - bikes[i][1]);
                v.push_back(p);
            }
        }
        sort(v.begin(), v.end(), cmp());
        vector<int> ans(l1, -1);
        vector<int> used(l2, 0);
        for (int i = 0; i < l1 * l2; ++i){
            if(used[v[i].bid] || ans[v[i].wid] >= 0) continue;
            if(ans[v[i].wid] < 0){
                ans[v[i].wid] = v[i].bid;
                used[v[i].bid] = true;
            }
        }
        return ans;
    }
};
void solve(){
	
}
int main(){
	solve();
	return 0;
}
