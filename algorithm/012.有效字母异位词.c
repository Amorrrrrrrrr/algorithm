bool isAnagram(char* s, char* t) {
    int chars[26] = {0};
    while(*s != '\0') {                 /* *s 才是访问字符 */
        chars[(*s - 'a')]++;
        s++;
    }
    while(*t != '\0') {
        chars[(*t - 'a')]--;
        t++;
    }

    for(int i = 0; i < 26; ++i) {
        if (chars[i] != 0) {
            return false;
        }
    }
    return true;
}