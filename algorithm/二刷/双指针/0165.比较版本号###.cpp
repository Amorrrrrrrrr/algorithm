class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int i = 0, j = 0;
        while (i < len1 || j < len2) {                      /* 比较所有的情况 */
            long long sum1 = 0, sum2 = 0;
            for (; i < len1 && version1[i] != '.';i++) {
                sum1 = sum1 * 10 + version1[i] - '0';
            }
            i++;                                            /* 跳过小数点 */
            for (; j < len2 && version2[j] != '.';j++) {
                sum2 = sum2 * 10 + version2[j] - '0';
            }
            j++;

            if (sum1 > sum2) return 1;
            else if (sum1 < sum2) return -1;
        }

        return 0;
    }
};