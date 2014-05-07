int getFail(char p[],int f[]){
	int m = strlen(p);
	f[0] = f[1] = 0;
	for(int i = 1;i<m;i++){
		int j = f[i];
		while(j&&p[i]!=p[j]) j = f[j];
		f[i+1] = p[i]==p[j]?j+1:0;
	}
	return m;
}

//s��ƥ�䴮��p��ģ�洮
bool find(char s[],char p[],int f[]){
	int n = strlen(s);
	int m = getFail(p,f);
	int j = 0;
	for(int i = 0;i<n;i++){
		while(j&&p[j]!=s[i]) j = f[j];
		if(p[j]==s[i]) j++;
		if(j==m) return true;
	}
	return false;
}