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
    int m, n, p, q;
    string data;
    RGB a;
    int rgb[3];
    cin >> m >> n >> p >> q;
    vector<vector<RGB> > object(n);
    //录入数据，同时改为十进制存入结构体
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
        //求平均
    vector<vector<RGB> >averrgb(high);
    int count = 0;
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
            if (averrgb[i][j].R != last.R || averrgb[i][j].G != last.G || averrgb[i][j].B != last.B) {//若不等于上一背景色
                if (averrgb[i][j].R == 0 && averrgb[i][j].G == 0 && averrgb[i][j].B == 0) {//为默认背景色，重置
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