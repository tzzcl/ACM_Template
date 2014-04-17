struct complex
{
	double r,i;
	complex(double real=0.0,double image=0.0){
		r=real;	i=image;
	}
	// 以下为三种虚数运算的定义
	complex operator + (const complex o){
		return complex(r+o.r,i+o.i);
	}
	complex operator - (const complex o){
		return complex(r-o.r,i-o.i);
	}
	complex operator * (const complex o){
		return complex(r*o.r-i*o.i,r*o.i+i*o.r);
	}
};
void brc(complex y[],int l) 
{
	int i,j,k;
	for(i=1,j=l/2;i<l-1;i++)
	{
		if(i<j)	swap(y[i],y[j]);
		k=l/2;
		while(j>=k) 
		{
			j-=k;
			k/=2;
		}
		if(j<k)	j+=k;
	}
}
void fft(complex y[],int l,double on) // FFT O(nlogn)
				     		// 其中on==1时为DFT，on==-1为IDFT
{
	register int h,i,j,k;
	complex u,t; 
	brc(y,l); 
	for(h=2;h<=l;h<<=1) 
	{
		complex wn(cos(on*2*pi/h),sin(on*2*pi/h));
		for(j=0;j<l;j+=h)
		{
			complex w(1,0);
			for(k=j;k<j+h/2;k++)
			{
				u=y[k];
				t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}
	if(on==-1)	for(i=0;i<l;i++)	y[i].r/=l; // IDFT
}
