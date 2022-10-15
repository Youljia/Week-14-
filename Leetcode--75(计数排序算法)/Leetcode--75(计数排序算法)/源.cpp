#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //ֻ��������ɫ 0,1,2
        vector<int> cnt(3, 0);
        //�洢ÿ����ɫ���ظ�����
        for (int num : nums)
            cnt[num]++;
        //cnt[0,nums[0])�洢����0
        for (int i = 0; i < cnt[0]; ++i)
            nums[i] = 0;
        //cnt[nums[0],nums[0]+nums[1])�洢����1
        for (int i = cnt[0]; i < cnt[0] +cnt[1]; ++i)
            nums[i] = 1;
        //cnt[nums[0]+nums[1],nums[0]+nums[1]+nums[3])�洢����2
        for (int i = cnt[0] + cnt[1]; i < cnt[0] + cnt[1] + cnt[2]; ++i)
            nums[i] = 2;
    }
};

int main() {
    vector<int> v{ 2,0,2,1,1,0 };
    Solution s;
    s.sortColors(v);
    for (int i : v)cout << i;
    return 0;
}