/* ����ջ���ҵ���ǰԪ���ұ�/��ߵ�һ��������/С��Ԫ����ʲô���ҵ����Ԫ�ص�ֵ�����±�֮���������������㡣
 * ʵ�֣���֤ջ�����Ԫ���ǵ������ߵݼ��ġ�
 * - ��ջ����ջ�׵�������ǰԪ���ұ�/��ߵ�һ���������Ԫ����ʲô
 * - ��ջ����ջ�׵ݼ�����ǰԪ���ұ�/��ߵ�һ������С��Ԫ����ʲô
 * ���ã����/��¼��������Ԫ�أ�Ȼ��ջ��Ԫ�غ͵�ǰ������Ԫ����һ���Ա�
 */

/* ջ����ŵ���Ԫ�ص��±� */
/* ��ջ����ջ�׵��� */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};