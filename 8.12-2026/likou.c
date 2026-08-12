#define _CRT_SECURE_NO_WARNINGS 
char* multiply(char* num1, char* num2) {
    int m = strlen(num1), n = strlen(num2);
    int* pos = (int*)calloc(m + n, sizeof(int));

    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            pos[p2] = sum % 10;
            pos[p1] += sum / 10;
        }

    int start = 0;
    while (start < m + n - 1 && pos[start] == 0) start++;  // 跳前导 0

    char* res = (char*)malloc(m + n - start + 1);
    for (int i = start; i < m + n; i++)
        res[i - start] = pos[i] + '0';
    res[m + n - start] = '\0';

    free(pos);
    return res;
}