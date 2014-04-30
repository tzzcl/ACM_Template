ll fastpow(ll a,ll b,int mod){//¿ìËÙÃÝ
	ll ans=1,temp=a;
	while (b>0){
		if (b&1) ans=(ans*temp)%mod;
		temp*=temp;temp%=mod;
		b>>=1;
	}
	return ans;
}

int millerrabin(ll a,ll n)//a^(n-1)%n==1
{
	ll x,m,k,b;
	m=n-1;
	k=0;
	while (!(m&1)) {k++;m=(m>>1);}
	b=fastpow(a,m,n);
	if (b==1||b==n-1) return 1;
	for (int i=1;i<k;i++)
	{
		x=(b*b)%n;
		if (x==n-1) return 1;
		b=x;
	}
	return 0;
}
int calc(ll n,int prime[]){//Miller_Rabin Test
	ll a;
	for (int i=0;i<5;i++)
	{
		a=prime[i];
		if (a<n&&millerrabin(a,n)==0) return 0;
	}
	return 1;
}