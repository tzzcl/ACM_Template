double disptoline(Point p,Point l1,Point l2){//��p��l1,l2�������ֱ�ߵľ���
	return fabs(cross(p,l1,l2))/l1.distTo(l2);
}