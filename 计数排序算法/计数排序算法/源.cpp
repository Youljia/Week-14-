#include<iostream>
#include<string>
#include<vector>
#include"Stuents.h"
using namespace std;

//���������㷨
void count_sort(vector<Stuents>& students) {
	int R = 3;
	vector<int> cnt(R, 0);
	vector<int> index(R + 1, 0);
	//ͳ��ÿ��Ԫ�س��ֵĴ���
	for (Stuents student : students) {
		cnt[student.get_score()]++;
	}
	//index[i]��Ӧ����i���ֵ���ߵ�һ��λ�õ��±�
	for (int i = 1; i < R + 1; i++)
		index[i] = cnt[i - 1] + index[i - 1];
	//���ռ����洢���������
	vector<Stuents> temp(students.size());
	for (Stuents student : students) {
		temp[index[student.get_score()]] = student;
		index[student.get_score()]++;
	}
	for (int i = 0; i < students.size(); ++i)
		students[i] = temp[i];
}

int main() {
	//��������--���������㷨�Ƿ��ܱ�֤�ȶ���
	Stuents s1("A", 2);
	Stuents s2("B", 0);
	Stuents s3("C", 0);
	Stuents s4("D", 1);
	Stuents s5("E", 2);
	vector<Stuents> students{ s1,s2,s3,s4,s5 };
	for (Stuents student : students)
		student.show();
	count_sort(students);
	for (Stuents student : students)
		student.show();
}