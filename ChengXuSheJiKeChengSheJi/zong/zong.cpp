#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct RGB
{
    int R;
    int G;
    int B;
}RGB;

void Printf(RGB a);
void Printfx(int n);
void change2(string a, int rgb[]);
void change3(string a, int rgb[]);

int main()
{
    int choose = 0;
    cout << "现在这里有三个小程序可供选择：" << endl;
    cout << "1 小明种苹果" << endl;
    cout << "2 小明种苹果(续)" << endl;
    cout << "3 字符画" << endl;
    cout << "0 退出程序" << endl;
    cout << "请输入想要运行的程序编号：";
    cin >> choose;
    while (choose) {
        if (choose == 1) {
            cout << "已进入小明种苹果程序，请输入合理的数据：" << endl;
            int N, M;//棵数和轮数
            int date, max = 0, othmax = 0, imax = 1, sum = 0;
            cin >> N >> M;
            vector< vector<int> > object(N);//建立矩阵
            for (int i = 0;i < N;i++)
                for (int j = 0;j < M + 1;j++) {
                    cin >> date;
                    object[i].push_back(date);
                }
            //定义第一组为最大
            for (int i = 1;i < M + 1;i++)
                max += object[0][i];
            //遍历查找
            for (int i = 0;i < N;i++) {
                for (int j = 0; j < M + 1; j++) {
                    sum += object[i][j];
                    if (j >= 1) {
                        othmax += object[i][j];
                    }
                }
                if (othmax < max) {
                    max = othmax;
                    imax = i + 1;
                }
                othmax = 0;
            }
            cout << sum << " " << imax << " " << -max << endl;
            cout << "小明种苹果运行结束！" << endl;
        }
        else if (choose == 2) {
            cout << "已进入小明种苹果（续）程序，请输入合理的数据：" << endl;
            int sum = 0, num = 0, E = 0;//总数，掉落棵数，连续3颗掉落掉落组数
            int onesum = 0;
            int N, m, data;
            int count = 0;//计数器
            cin >> N;
            vector<vector<int> > object(N);
            vector<bool> isfall(N, false);
            //输入数据
            for (int i = 0;i < N;i++) {
                cin >> m;
                for (int j = 0; j < m; j++) {
                    cin >> data;
                    object[i].push_back(data);
                }
            }
            //遍历
            for (int i = 0;i < N;i++) {
                onesum = object[i][0];
                for (int j = 1; j < object[i].size(); j++) {
                    if (object[i][j] > 0 && object[i][j] < onesum) {
                        onesum = object[i][j];
                        isfall[i] = true;
                    }
                    else if (object[i][j] <= 0)
                        onesum += object[i][j];
                }
                sum += onesum;
            }
            //记录掉果情况
            for (int i = 0;i < N;i++) {
                if (isfall[i]) {
                    count++;
                    num++;
                    if (count % 3 == 0) {
                        E++;
                        count--;
                    }
                }
                else {
                    count = 0;
                }
            }
            if (isfall[N - 2] && isfall[N - 1] && isfall[0])
                E++;
            if (isfall[N - 1] && isfall[1] && isfall[0])
                E++;
            cout << sum << " " << num << " " << E << endl;
            cout << "小明种苹果（续）运行结束！" << endl;
        }
        else if (choose == 3) {
            cout << "已进入字符画程序，请输入合理的数据：" << endl;
            int m, n, p, q;
            string data;
            RGB a;
            int rgb[3];
            cin >> m >> n >> p >> q;
            vector<vector<RGB> > object(n);
            //存放数据
            for (int i = 0;i < n;i++)
                for (int j = 0;j < m;j++) {
                    cin >> data;
                    change2(data, rgb);
                    a.R = rgb[0];
                    a.G = rgb[1];
                    a.B = rgb[2];
                    object[i].push_back(a);
                }
            int high = n / q, wide = m / p;
            vector<vector<RGB> >averrgb(high);
            int count = 0;
            //求平均
            for (int i = 0;i < n;i += q) {
                for (int j = 0;j < m;j += p) {
                    a.R = a.G = a.B = 0;
                    for (int x = 0;x < q;x++) {
                        for (int y = 0;y < p;y++) {
                            a.R += object[i + x][j + y].R;
                            a.G += object[i + x][j + y].G;
                            a.B += object[i + x][j + y].B;
                        }
                    }
                    a.R /= (p * q);
                    a.G /= (p * q);
                    a.B /= (p * q);
                    averrgb[count].push_back(a);
                }
                count++;
            }
            RGB last;
            //打印
            for (int i = 0;i < high;i++) {
                last.R = last.B = last.G = 0;
                for (int j = 0;j < wide;j++) {
                    if (averrgb[i][j].R != last.R || averrgb[i][j].G != last.G || averrgb[i][j].B != last.B) {
                        if (averrgb[i][j].R == 0 && averrgb[i][j].G == 0 && averrgb[i][j].B == 0) {
                            cout << "\\x1B\\x5B\\x30\\x6D";
                        }
                        else
                            Printf(averrgb[i][j]);
                        last.R = averrgb[i][j].R;
                        last.G = averrgb[i][j].G;
                        last.B = averrgb[i][j].B;
                    }
                    cout << "\\x20";
                }
                if (last.R || last.G || last.B)
                    cout << "\\x1B\\x5B\\x30\\x6D";
                cout << "\\x0A";
            }
            cout <<endl<< "字符画运行结束！" << endl;
        }
        else {
            cout << "请输入正确的程序编号！" << endl;
        }
        cout << "请输入想要运行的程序编号：";
        cin >> choose;
    }
    return 0;
}


void Printfx(int n) {
    if (n < 10)
        cout << "\\x" << 30 + n;
    else if (n < 100)
        cout << "\\x" << n / 10 + 30 << "\\x" << n % 10 + 30;
    else
        cout << "\\x" << n / 100 + 30 << "\\x" << (n / 10) % 10 + 30 << "\\x" << n % 10 + 30;
}
void change3(string a, int rgb[]) {
    rgb[0] = rgb[1] = rgb[2] = 0;
    for (int i = 0;i < 6;i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            rgb[i / 2] *= 16;
            rgb[i / 2] += (a[i] - '0');
        }
        if (a[i] >= 'a' && a[i] <= 'f') {
            rgb[i / 2] *= 16;
            rgb[i / 2] += (a[i] - 'a' + 10);
        }
        if (a[i] >= 'A' && a[i] <= 'F') {
            rgb[i / 2] *= 16;
            rgb[i / 2] += (a[i] - 'A' + 10);
        }
    }
}
void change2(string a, int rgb[]) {
    string put;
    if (a.size() == 7) {
        for (int i = 0;i < 6;i++)
            put.push_back(a[i + 1]);
    }
    if (a.size() == 4) {
        for (int i = 1, j = 0;i < 7;i++, j++)
            put.push_back(a[j / 2 + 1]);
    }
    if (a.size() == 2) {
        for (int i = 0;i < 6;i++)
            put.push_back(a[1]);
    }
    change3(put, rgb);
}

void Printf(RGB a) {
    cout << "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
    Printfx(a.R);
    cout << "\\x3B";
    Printfx(a.G);
    cout << "\\x3B";
    Printfx(a.B);
    cout << "\\x6D";
}