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
double tidu(double x[],double fx[],int n){//�ݶ��½�������ֵ��fΪ������ֵ��f1,f2�ȵ�Ϊ��һ�����ڶ����ȵȱ�����ƫ��
	//xΪ��ʼ����ֵ��nΪ��������
	double step=0.1;//��������
	//����ƫ��
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