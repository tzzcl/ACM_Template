//����STL�������
find(begin,end,val) //Ѱ�ҵ�һ�����ֵ�ֵ
find_end(first1,last1,first2,last2) //Ѱ��first1~last1��first2~last2���һ�γ��ֵĵ�ַ
search(first1,last1,first2,last2) //Ѱ��first1~last1��first2~last2��һ�γ��ֵĵ�ַ
find_first_of(first1,last1,first2,last2) //Ѱ��first1~last1�е�һ��������first2~last2�е�Ԫ��O(n^2)
adjacent_find(first,last)//Ѱ�ҵ�һ����������ȵ�Ԫ�ص�λ��
count(begin,end,val) //Ѱ��ĳֵ���ִ���
mismatch(fi1,la1,fi2,la2)//Ѱ�ҵ�һ����ƥ���λ�ã����ز�ƥ���ָ��
equal(fi1,la1,fi2,la2)//�ж����������Ƿ����
search_n(fi,la,count,val) //Ѱ������count��Ϊvalֵ��λ��
copy(fi,la,re)//����fi~la��re�����λ��
copy_backward(fi,la,re)//�Ӻ���ǰ����
swap(a,b)//����a,b
swap_ranges(fi1,la1,fi2) //fi1��fi2ȫ������
replace(fi,la,old,newi) //��oldȫ���滻��newi
fill(fi,la,val)//ȫ������val
remove(fi,la,val)//ȥ��val
unique(fi,la) //ȥ��
reverse(fi,la) //��ת
random_shuffle(fi,la) //�������
sort(fi,la)//����
nth_element(fi,lo,la)//��loΪλ�û���
lower_bound(fi,la,val)//����>=val��ַ
upper_bound(fi,la,val)//����>val��ַ
binary_search(fi,la,val)//���ֲ���
min(a,b) //������Сֵ
max(a,b) //�������ֵ
min_element(fi,la)//������СԪ��
max_element(fi,la)//�������Ԫ��
lexicographical_compare(fi1,la1,fi2,la2)//�ֵ���Ƚ�
next_permutation(fi,la)//��һ������
prev_permutation(fi,la)//ǰһ������