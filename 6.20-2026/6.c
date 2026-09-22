//P5711
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
        printf("%d", 1);
    else
        printf("%d", 0);
    return 0;
}
//B2010
#include <stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d", a / b, a % b);
    return 0;
}
//B2008
#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", (a + b) * c);
    return 0;
}
//B2009
#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", (a + b) / c);
    return 0;
}

//P5709
#include <stdio.h>
int main() {
    int m, t, s;
    scanf("%d%d%d", &m, &t, &s);
    if (t == 0) {
        printf("0");
    }
    else {
        int eaten = s / t;
        if (s % t != 0) eaten++;
        if (eaten >= m)
            printf("0");
        else
            printf("%d", m - eaten);
    }
    return 0;
}
//P2433
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//
//int main() {
//    int T;
//    cin >> T;
//    switch (T) {
//    case 1:
//        cout << "I love Luogu!" << endl;
//        break;
//    case 2:
//        cout << 6 << " " << 4 << endl;
//        break;
//    case 3:
//        cout << 14 / 4 << endl;
//        cout << 14 / 4 * 4 << endl;
//        cout << 14 % 4 << endl;
//        break;
//    case 4:
//        cout << fixed << setprecision(3) << 500.0 / 3 << endl;
//        break;
//    case 5:
//        cout << (260 + 220) / (12 + 20) << endl;
//        break;
//    case 6:
//        cout << sqrt(6 * 6 + 9 * 9) << endl;
//        break;
//    case 7:
//        cout << 100 + 10 << endl;
//        cout << 110 - 20 << endl;
//        cout << 0 << endl;
//        break;
//    case 8: {
//        double pi = 3.141593, r = 5;
//        cout << 2 * pi * r << endl;
//        cout << pi * r * r << endl;
//        cout << 4.0 / 3 * pi * r * r * r << endl;
//        break;
//    }
//    case 9:
//        cout << 22 << endl;
//        break;
//    case 10:
//        cout << 9 << endl;
//        break;
//    case 11:
//        cout << 100.0 / (8 - 5) << endl;
//        break;
//    case 12:
//        cout << 'M' - 'A' + 1 << endl;
//        cout << char('A' + 18 - 1) << endl;
//        break;
//    case 13: {
//        double v = 4.0 / 3 * 3.141593 * (4 * 4 * 4 + 10 * 10 * 10);
//        cout << int(cbrt(v)) << endl;
//        break;
//    }
//    case 14:
//        cout << 50 << endl;
//        break;
//    }
//    return 0;
//}
//P5711
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
        printf("%d", 1);
    else
        printf("%d", 0);
    return 0;
}