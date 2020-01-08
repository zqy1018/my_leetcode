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
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        struct cmp{
            bool operator ()(const Interval &i1, const Interval &i2){
                if(i1.start == i2.start) return i1.end < i2.end;
                return i1.start < i2.start; 
            }
        };
        int n = intervals.size();
        vector<Interval> ans;
        if(!n) return ans;
        sort(intervals.begin(), intervals.end(), cmp());
        int st = intervals[0].start, ed = intervals[0].end;
        for (int i = 1; i < n; ++i){
            if(intervals[i].start <= ed)
                ed = max(ed, intervals[i].end);
            else{
                ans.push_back(Interval(st, ed));
                st = intervals[i].start, ed = intervals[i].end;
            }
        }
        ans.push_back(Interval(st, ed));
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
