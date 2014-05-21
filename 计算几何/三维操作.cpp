Point3 pvec(Plane3 s){//ȡƽ�淨����
	return (s.a-s.b)^(s.b-s.c);
}
Point3 pvec(Point3 a,Point3 b,Point3 c){
	return (a-b)^(b-c);
}
int dot3_inline(Point3 p1,Point3 p2,Point3 p3){//�����㹲��
	return ((p1-p2)^(p2-p3)).len()<eps;
}
int dot3_onplane(Point3 a,Point3 b,Point3 c,Point3 d){//���ĵ㹲��
	return sign(pvec(a,b,c)*(d-a))==0;
}
int dot3_online(Point3 p,Point3 l1,Point3 l2){//�е��Ƿ����߶���,�����˵�͹���
	return sign(((p-l1)^(p-l2)).len())==0&&(l1.x-p.x)*(l2.x-p.x)<eps&&
		(l1.y-p.y)*(l2.y-p.y)<eps&&(l1.z-p.z)*(l2.z-p.z)<eps;
}
int dot3_online_ex(Point3 p,Point3 l1,Point3 l2){//�е��Ƿ����߶���,�������˵�
	return dot3_online(p,l1,l2)&&sign(p.x-l1.x)!=0||sign(p.y-l1.y)!=0||sign(p.z-l1.z)!=0&&
		sign(p.x-l2.x)!=0||sign(p.y-l2.y)!=0||sign(p.z-l2.z)!=0;
}
int dot3_inplane(Point3 p,Point3 s1,Point3 s2,Point3 s3){//�е��Ƿ��ڿռ���������,�����߽�,���㹲��������
	return sign(((s1-s2)^(s1-s3)).len()-((p-s1)^(p-s2)).len()-((p-s2)^(p-s3)).len()-
		((p-s3)^(p-s1)).len())==0;
}
int same_side3(Point3 p1,Point3 p2,Point3 l1,Point3 l2){//���������߶�ͬ��,�����߶��Ϸ���0,������������
	return ((l1-l2)^(p1-l2))*((l1-l2)^(p2-l2))<eps;
}
int oppo_side3(Point3 p1,Point3 p2,Point3 l1,Point3 l2){//���������߶����,�����߶��Ϸ���0,������������
	return ((l1-l2)^(p1-l2))*((l1-l2)^(p2-l2))<-eps;
}
int same_side_plane(Point3 p1,Point3 p2,Point3 s1,Point3 s2,Point3 s3){//��������ƽ��ͬ��,����ƽ���Ϸ���0
	return (pvec(s1,s2,s3)*(p1-s1))*(pvec(s1,s2,s3)*(p2-s1))>eps;
}
int oppo_side_plane(Point3 p1,Point3 p2,Point3 s1,Point3 s2,Point3 s3){//��������ƽ�����,����ƽ���Ϸ���0
	return pvec(s1,s2,s3)*(p1-s1)*(pvec(s1,s2,s3)*(p2-s1))<-eps;
}

int parallel_Line(Point3 u1,Point3 u2,Point3 v1,Point3 v2){//����ֱ��ƽ��
	return ((u1-u2)^(v1-v2)).len()<eps;
}
int parallel_Plane(Point3 u1,Point3 u2,Point3 u3,Point3 v1,Point3 v2,Point3 v3){//����ƽ��ƽ��
	return (pvec(u1,u2,u3)^pvec(v1,v2,v3)).len()<eps;
}
int parallel_Line_Plane(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//��ֱ����ƽ��ƽ��
	return sign((l1-l2)*pvec(s1,s2,s3))==0;
}
int perpend_LtoP(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//��ֱ����ƽ�洹ֱ
	return ((l1-l2)^pvec(s1,s2,s3)).len()<eps;
}
int intersect3(Point3 u1,Point3 u2,Point3 v1,Point3 v2){//�����߶��ཻ,�����˵�Ͳ����غ�
	if (!dot3_onplane(u1,u2,v1,v2)) return 0;
	if (!dot3_inline(u1,u2,v1)||!dot3_inline(u1,u2,v2))
		return !same_side3(u1,u2,v1,v2)&&!same_side3(v1,v2,u1,u2);
	return dot3_online(u1,v1,v2)||dot3_online(u2,v1,v2)||dot3_online(v1,u1,u2)||dot3_online(v2,u1,u2);
}
int intersect3_ex(Point3 u1,Point3 u2,Point3 v1,Point3 v2){//�����߶��ཻ,�������˵�Ͳ����غ�
	return dot3_onplane(u1,u2,v1,v2)&&oppo_side3(u1,u2,v1,v2)&&oppo_side3(v1,v2,u1,u2);
}

int intersect3_LtoP(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//���߶���ռ��������ཻ,�������ڱ߽��(����)����
	return !same_side_plane(l1,l2,s1,s2,s3)&&!same_side_plane(s1,s2,l1,l2,s3)&&
		!same_side_plane(s2,s3,l1,l2,s1)&&!same_side_plane(s3,s1,l1,l2,s2);
}
int intersect3_LtoPex(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//���߶���ռ��������ཻ,���������ڱ߽��(����)����
	return oppo_side_plane(l1,l2,s1,s2,s3)&&oppo_side_plane(s1,s2,l1,l2,s3)&&
		oppo_side_plane(s2,s3,l1,l2,s1)&&oppo_side_plane(s3,s1,l1,l2,s2);
}
Point3 intersection_LtoL(Point3 u1,Point3 u2,Point3 v1,Point3 v2){
	//������ֱ�߽���,ע�������ж�ֱ���Ƿ����ƽ��!
//�߶ν������������߶��ཻ(ͬʱ����Ҫ�ж��Ƿ�ƽ��!)

	Point3 ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
		((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	ret.z+=(u2.z-u1.z)*t;
	return ret;
}
Point3 intersection_LtoP(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){
//����ֱ����ƽ�潻��,ע�������ж��Ƿ�ƽ��,����֤���㲻����!
//�߶κͿռ������ν����������ж�

	Point3 ret=pvec(s1,s2,s3);
	double t=(ret.x*(s1.x-l1.x)+ret.y*(s1.y-l1.y)+ret.z*(s1.z-l1.z))/
		(ret.x*(l2.x-l1.x)+ret.y*(l2.y-l1.y)+ret.z*(l2.z-l1.z));
	ret.x=l1.x+(l2.x-l1.x)*t;
	ret.y=l1.y+(l2.y-l1.y)*t;
	ret.z=l1.z+(l2.z-l1.z)*t;
	return ret;
}
Line3 intersection_PtoP(Point3 u1,Point3 u2,Point3 u3,Point3 v1,Point3 v2,Point3 v3){
//������ƽ�潻��,ע�������ж��Ƿ�ƽ��,����֤���㲻����!
	Line3 ret;
	ret.s=(parallel_Line_Plane(v1,v2,u1,u2,u3))?(intersection_LtoP(v2,v3,u1,u2,u3)):(intersection_LtoP(v1,v2,u1,u2,u3));
	ret.e=(parallel_Line_Plane(v3,v1,u1,u2,u3))?(intersection_LtoP(v2,v3,u1,u2,u3)):(intersection_LtoP(v3,v1,u1,u2,u3));
	return ret;
}
double ptoline(Point3 p,Point3 l1,Point3 l2){
//�㵽ֱ�߾���
	return ((p-l1)^(l2-l1)).len()/l1.Distto(l2);
}
double ptoplane(Point3 p,Point3 s1,Point3 s2,Point3 s3){
//�㵽ƽ�����
	return fabs(pvec(s1,s2,s3)*(p-s1))/pvec(s1,s2,s3).len();
}
double linetoline(Point3 u1,Point3 u2,Point3 v1,Point3 v2){
//ֱ�ߵ�ֱ�߾���
	Point3 n=(u1-u2)^(v1-v2);
	return fabs((u1-v1)*n)/n.len();
}
double angle_cos_Line(Point3 u1,Point3 u2,Point3 v1,Point3 v2){
//��ֱ�߼н�cosֵ
	return (u1-u2)*(v1-v2)/(u1-u2).len()/(v1-v2).len();
}
double angle_cos_Plane(Point3 u1,Point3 u2,Point3 u3,Point3 v1,Point3 v2,Point3 v3){
//��ƽ��н�cosֵ
	return pvec(u1,u2,u3)*pvec(v1,v2,v3)/pvec(u1,u2,u3).len()/pvec(v1,v2,v3).len();
}
//a���� Ob ��������ʱ����ת���� angle ,sin(angle),cos(angle)������������پ������⡣
Point3 rotate(Point3 a,Point3 b,double angle){
	double l=b.len();b.x/=l;b.y/=l;b.z/=l;
	Point3 e3=b;double len=a*e3;
	Point3 e1=a-e3*len;
	if (e1.len()>eps){
		l=e1.len();e1.x/=l;e1.y/=l;e1.z/=l;
	}
	else return a;
	Point3 e2=e1^e3;
	double x1,y1,x,y;y1=a*e1;x1=a*e2;
	x=x1*cos(angle)-y1*sin(angle);y=x1*sin(angle)+y1*cos(angle);
	return e3*len+e1*y+e2*x;
}