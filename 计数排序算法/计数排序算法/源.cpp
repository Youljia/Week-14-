#include<iostream>
#include<string>
#include<vector>
#include"Stuents.h"
using namespace std;

//计数排序算法
void count_sort(vector<Stuents>& students) {
	int R = 3;
	vector<int> cnt(R, 0);
	vector<int> index(R + 1, 0);
	//统计每个元素出现的次数
	for (Stuents student : students) {
		cnt[student.get_score()]++;
	}
	//index[i]对应的是i出现的左边第一个位置的下标
	for (int i = 1; i < R + 1; i++)
		index[i] = cnt[i - 1] + index[i - 1];
	//另开空间来存储有序的数组
	vector<Stuents> temp(students.size());
	for (Stuents student : students) {
		temp[index[student.get_score()]] = student;
		index[student.get_score()]++;
	}
	for (int i = 0; i < students.size(); ++i)
		students[i] = temp[i];
}

int main() {
	//测试用例--计数排序算法是否能保证稳定性
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