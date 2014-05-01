bool graham_cmp(Point a,Point b)//͹���ȽϺ���
{
    return (a.y<b.y || a.y==b.y && a.x<b.x);
}
int gmult(Point &B,Point &A,Point &O)
{//���ǵ���B��,ע�����㹲��,OA���ο��������Ⱥţ�ȥ�ص�͹��ߵ�
    return (B.y-O.y)*(A.x-O.x)<=(A.y-O.y)*(B.x-O.x);
}

int Graham(Point pnt[],int n,Point graham[])//͹��
{
     int top=1;
     sort(pnt,pnt+n,graham_cmp);//�ӵ͵�������
  
     int tmp = 0;
     for (int i = 1;i<n;i++)
     {
         if (pnt[i].x == pnt[i-1].x && pnt[i].y == pnt[i-1].y)
         {
            pnt[tmp] = pnt[i];
         }
         else
         {
             pnt[++tmp] = pnt[i];
         }
     }
     n = tmp + 1;
  
     if (n==0) return 0;graham[0]=pnt[0];
     if (n==1) return 1;graham[1]=pnt[1];
     if (n==2) return 2;
  
     for (int i=2;i<n;i++)//Ԥ��������
     {
         while(top && gmult(pnt[i],graham[top],graham[top-1]))
             top--;
         graham[++top]=pnt[i];
     }//�ӵ������Ұ��
  
     graham[++top]=pnt[n-2];
     for (int i=n-3,tmp=top-1;i>=0;i--)//mind the tmp
     {
         while(top!=tmp && gmult(pnt[i],graham[top],graham[top-1]))
             top--;
         graham[++top]=pnt[i];
     }//������������
  
     return top;//��͵㱻��������
}