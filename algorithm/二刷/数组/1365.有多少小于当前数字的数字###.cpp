/* ���� + ��ϣ�� */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int hash[101] = { 0 };

        vector<int> ret;
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());                       /* ���� */
        for (int i = vec.size() - 1; i >= 0; i--) {         /* �Ӻ���ǰ���¹�ϣ�� */
            hash[vec[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            vec[i] = hash[nums[i]];                         /* ��¼��� */
        }

        return vec;
    }
};