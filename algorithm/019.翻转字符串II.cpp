class Solution {
public:
    void reverseString(string& s, int begin, int end) {
        int left = begin;
        int right = end - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++; right--;
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {             /* for ѭ��ÿ�ε��� 2k */
            if (i + k - 1 <= s.size() - 1) {                    /* �߽����� */
                reverseString(s, i, i + k);
            }
            else {
                reverseString(s, i, s.size());
            }
        }
        return s;
    }
};

/* ��Ѵ� */
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
            // 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                // 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};