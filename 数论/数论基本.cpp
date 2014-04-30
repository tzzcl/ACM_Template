ll fastpow(ll a,ll b,int mod){//������
	ll ans=1,temp=a;
	while (b>0){
		if (b&1) ans=(ans*temp)%mod;
		temp*=temp;temp%=mod;
		b>>=1;
	}
	return ans;
}
ll gcd(ll m,ll n){//���Լ��
	if (m<n) swap(m,n);
	if (n==0) return m;
	else return gcd(n,m%n);
}
ll lcm(ll a,ll b){//��С������
	ll temp=gcd(a,b);
	return a*b/temp;
}
inline int exgcd(int a, int b, int &x, int &y) {//��չEuclid
    if(!b) {
        x = 1; y = 0;
        return a;
    }
    int ret = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ret;
}
int china(int n, int a[], int m[]) {// �й�ʣ�ඨ��,aΪ������mΪ����
    int M = 1;
    for(int i = 0;i < n; i++) M *= m[i];
    int ret = 0;
    for(int i = 0;i < n; i++) {
        int w = M/m[i], x, y;
        int d = exgcd(w, m[i], x, y);
        ret = (ret + x*w*a[i])%M;
    }
    return (ret + M)%M;
}
void Elshai(bool check[],int prime[],int N){//����ɸ������
	memset(check,0,sizeof(check));
	memset(prime,0,sizeof(prime));
	int cnt=0;
for (int i=2;i<=N;i++){
		if (!check[i]) prime[cnt++]=i;
for (int j=0;j<cnt;j++){
		if ((i)*prime[j]>N) break;
		check[i*prime[j]]=true;
		if (i%prime[j]==0) break;
	}
	}
}