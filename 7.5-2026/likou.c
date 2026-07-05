int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;   // 从末尾开始
    int count = 0;

    while (i >= 0 && s[i] == ' ')   // 跳过末尾空格
        i--;

    while (i >= 0 && s[i] != ' ') { // 统计最后一个单词
        count++;
        i--;
    }

    return count;
}