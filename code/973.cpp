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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        struct Node{
            int id;
            double dis;
            bool cmp(const Node &n1, const Node &n2){
                return n1.dis > n2.dis;
            }
        };
        struct Cmp{
            bool operator ()(const Node &n1, const Node &n2){
                return n1.dis < n2.dis;
            }
        };
        vector<Node> pq;
        int n = points.size();
        if(K == n) return points;
        for (int i = 0; i < K; ++i){
            Node nd;
            nd.dis = hypot(points[i][0], points[i][1]);
            nd.id = i;
            pq.push_back(nd);
        }
        make_heap(pq.begin(), pq.end(), Cmp());
        for (int i = K; i < n; ++i){
            Node nd;
            nd.dis = hypot(points[i][0], points[i][1]);
            nd.id = i;
            pq.push_back(nd);
            push_heap(pq.begin(), pq.end(), Cmp());
            pop_heap(pq.begin(), pq.end(), Cmp()); //nlogk
            pq.pop_back();
        }
        vector<vector<int> > ans;
        for (int i = 0; i < K; ++i)
            ans.push_back(points[pq[i].id]);
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
