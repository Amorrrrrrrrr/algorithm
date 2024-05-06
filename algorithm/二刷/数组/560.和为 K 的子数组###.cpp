/* ö�٣�����ʱ�����ƣ� */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {     /* �� start ��β���������Ƿ��������� */
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

/* ��ϣ�� + ǰ׺�� */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;                                           /* <�� i Ϊβ������ĺ�, �͵ĸ���> */
        umap[0] = 1;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (umap.find(sum - k) != umap.end()) ret += umap[sum - k];         /* ǰ׺�͵�ʹ�� */
            umap[sum]++;                                                        /* ��ʹ�ú���ӣ���֤������Ĵ��� */
        }
        return ret;
    }
};