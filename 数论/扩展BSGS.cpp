const int maxn=65535;
ll fastpow(ll a,ll b,int mod){//快速幂
	ll ans=1,temp=a;
	while (b>0){
		if (b&1) ans=(ans*temp)%mod;
		temp*=temp;temp%=mod;
		b>>=1;
	}
	return ans;
}

ll gcd(ll m,ll n){//最大公约数
	if (m<n) swap(m,n);
	if (n==0) return m;
	else return gcd(n,m%n);
}

inline int exgcd(int a, int b, int &x, int &y) {//扩展Euclid
    if(!b) {
        x = 1; y = 0;
        return a;
    }
    int ret = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ret;
}

struct hash{
	int a,b,next;
}Hash[maxn<<1];
int flag[maxn];
int top,idx;
void insert(int a,int b){
	int k=b&maxn;
	if (flag[k]!=idx){
		flag[k]=idx;
		Hash[k].next=-1;
		Hash[k].a=a;
		Hash[k].b=b;
		return ;
	}
	while (Hash[k].next!=-1){
		if (Hash[k].b==b) return ;
		k=Hash[k].next;
	}
	Hash[k].next=++top;
	Hash[top].next=-1;
	Hash[top].a=a;
	Hash[top].b=b;
}
int find(int b){
	int k=b&maxn;
	if (flag[k]!=idx) return -1;
	while (k!=-1){
		if (Hash[k].b==b) return Hash[k].a;
		k=Hash[k].next;
	}
	return -1;
}

int Inval(int a,int b,int n){
	int x,y,e;
	exgcd(a,n,x,y);
	e=(ll)x*b%n;
	return e<0?e+n:e;
}
int BabyStep(int A,int B,int C){
	top=maxn;++idx;
	ll buf=1%C,D=buf,K=0;
	int i,d=0,tmp;
	for (i=0;i<=100;buf=buf*A%C,++i)
		if (buf==B) return i;
		while ((tmp=gcd(A,C))!=1){
			if (B%tmp) return -1;
			++d;
			C/=tmp;
			B/=tmp;
			D=D*A/tmp%C;
		}
		int M=(int)ceil(sqrt(double(C)));
		for (buf=1%C,i=0;i<=M;buf=buf*A%C,++i)
			insert(i,buf);
		for (int i=0,K=fastpow(A,M,C);i<=M;D=D*K%C,++i){
			tmp=Inval(int(D),B,C);int w;
			if (tmp>0&&(w=find(tmp))!=-1)
				return i*M+w+d;
		}
	return -1;
}
