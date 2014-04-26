inline double f(double x[],int n){
	double ans=0;
	for (int i=0;i<n;i++)
		ans+=sqr(x[i]);
	return ans;
}
inline double f1(double x){
	return 2*x;
}
inline double f2(double x){
	return 2*x;
}
double tidu(double x[],double fx[],int n){//梯度下降求函数最值，f为函数求值，f1,f2等等为第一个，第二个等等变量的偏导
	//x为初始向量值，n为变量个数
	double step=0.1;//迭代步长
	//计算偏导
	for (int i=0;i<n;i++){
		fx[i]=f1(x[i]);
	}
	double last_step=f(x,n);
	for (int i=0;i<n;i++)
		x[i]=x[i]-step*fx[i];
	double this_step=f(x,n);
	while (fabs(this_step-last_step)>eps){
		for (int i=0;i<n;i++){
		fx[i]=f1(x[i]);
		}
		for (int i=0;i<n;i++)
			x[i]=x[i]-step*fx[i];
		last_step=this_step;
		this_step=f(x,n);
	}
	return this_step;
}