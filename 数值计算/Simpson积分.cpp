inline double f(double x){
	return x;
}
double simpson(double a,double b){//三点Simpson积分
	double c=(a+b)/2;
	return (f(a)+4*f(c)+f(b))*(b-a)/6;
}
double asr(double a,double b,double A){//主递归函数，A为Simpson(a,b)
	double c=(a+b)/2;
	double L=simpson(a,c),R=simpson(c,b);
	if (fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15;
	return asr(a,c,L)+asr(c,b,R);
}