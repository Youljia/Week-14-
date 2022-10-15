# Week-14-

# 数据结构与算法

## 计数排序算法（非比较的排序算法）

* 大致逻辑

  * 通过统计每一个元素i出现的个数cnt，则对于一个长度为cnt的区间的所有元素都是i;
  * Leetcode 75颜色分类问题

* 重要性质--稳定性

  * 排序算法的稳定性 --> 在排序过程中，相同元素排序前后的相对位置不变

* 实现（代码解读）

  ```c++
  void count_sort(vector<Stuents>& students) {
      //R是不同元素的个数
  	int R = 3;
  	vector<int> cnt(R, 0);
  	vector<int> index(R + 1, 0);
  	//统计每个元素出现的次数
  	for (Stuents student : students) {
  		cnt[student.get_score()]++;
  	}
  	//index[i]对应的是i出现的第一个位置的下标
      //index[i+1]存储的是元素最后一个下标的下一个下标
      //所以每个元素的位置是[index[i],index[i+1])
  	for (int i = 1; i < R + 1; i++)
  		index[i] = cnt[i - 1] + index[i - 1];
  	//另开空间来存储有序的数组
      //防止原来的元素被覆盖，确保计数排序算法的稳定性
  	vector<Stuents> temp(students.size());
  	for (Stuents student : students) {
  		temp[index[student.get_score()]] = student;
  		index[student.get_score()]++;
  	}
  	for (int i = 0; i < students.size(); ++i)
  		students[i] = temp[i];
  }
  ```

  
