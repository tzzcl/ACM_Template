void Elshai(bool check[],int prime[],int N){//线性筛求质数
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
void Euler(bool check[],int prime[],int fail[],int n){
//线性筛求欧拉函数，类似可推广到积性函数
	fail[1]=1;
	int total=0;
	for (int i=2;i<=n;i++){
		if (!check[i]){
			prime[total++]=i;
			fail[i]=i-1;
		}
		for (int j=0;j<total;j++){
			if (i*prime[j]>n) break;
			check[i*prime[j]]=1;
			if (i%prime[j]==0){
				fail[i*prime[j]]=fail[i]*prime[j];
				break;
			}else
				fail[i*prime[j]]=fail[i]*(prime[j]-1);
		}
	}
}