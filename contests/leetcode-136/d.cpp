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

class SA{
public:
    int *r;
    int *sa, *wa, *wb, *wv, *cnt;
    int *Rank, *height, R, nn;
    SA(int n, string &S){
        r = new int[100005];
        wa = new int[100005];
        wb = new int[100005];
        wv = new int[100005];
        cnt = new int[100005]{0};
        Rank = new int[100005];
        height = new int[100005];
        nn = n, R = 26;
        for (int i = 0; i < n; ++i) 
            r[i] = S[i] - 'a';
        r[n] = 0;
    }
    int cmp(int *r,int a,int b,int l){
        return r[a]==r[b]&&r[a+l]==r[b+l];
    }
    void build_sa(int n,int m){
        int i,j,p,*x=wa,*y=wb;
        for(i=0;i<m;i++)cnt[i]=0;
        for(i=0;i<n;i++)cnt[x[i]=r[i]]++;
        for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;i--)sa[--cnt[x[i]]]=i;
        for(j=1,p=1;p<n;j<<=1,m=p){
            for(p=0,i=n-j;i<n;i++)y[p++]=i;
            for(i=0;i<n;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
            for(i=0;i<n;i++)wv[i]=x[y[i]];
            for(i=0;i<m;i++)cnt[i]=0;
            for(i=0;i<n;i++)cnt[wv[i]]++;
            for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
            for(i=n-1;i>=0;i--)sa[--cnt[wv[i]]]=y[i];
            swap(x,y);
            for(p=1,x[sa[0]]=0,i=1;i<n;i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;		
        }
    }
    void build_height(int *r,int *sa,int *height,int n){
        int i,j,k=0;
        for(i=1;i<=n;i++)Rank[sa[i]]=i;
        for(i=0;i<n;height[Rank[i++]]=k)
            for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
    }
    void init(){
        build_sa(nn+1,R);
        //只有sa[1-n]才是有意义的 
        build_height(r,sa,height,nn);
    }
    int solve(){
        int ll=0,rr=nn,mid,ans;
        while(rr-ll>1){
            mid=(ll+rr)/2;
            //mid:理想长度
            int cur=1,flag=0;
            for(int i=2;i<=nn;i++){
                if(height[i]>=mid)cur++;
                else{
                    if(cur>=2)flag=1;
                    cur=1;
                }	
            }
            if(cur>=2)flag=1;
            if(flag)ll=mid;
            else rr=mid;
        }
        int cur=1,flag=0;
        for(int i=2;i<=nn;i++){
            if(height[i]>=rr)cur++;
            else{
                if(cur>=2)flag=1;
                cur=1;
            }	
        }
        if(cur>=2)flag=1;
        if(flag)ll=rr;
        return ll;
    }
};


class Solution {
public:
    string longestDupSubstring(string S) {
        int n = S.size();
        SA ssa(n, S);
        ssa.init();
        int ll = ssa.solve();
        if(!ll) return string("");
        for (int i = 0; i < n - ll; ++i){
            if(S.find(S.substr(i, ll), i + 1) >= 0) return S.substr(i, ll);
        }
        return string("");
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
