/*首先将输入转化为十进制数字存入结构体中，然后将每一个数据拆分为单个数，转化为ASCII，再转化为转义十六进制。*/
#include <iostream>
#include <vector>
#include <regex>
#include <string>
using namespace std;
//颜色值结构体
typedef int Typename;
typedef struct html {
    Typename first;
    Typename second;
    Typename tired;
    string head = "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
}html;

html change(string& y);//将输入转化为十进制数
html average(vector<vector<html> >& a, int i, int j, int high, int wide);//求区块平均值，并存入新的结构体数组
int change2(string& x, int n);//十进制数转化为ASCII
void TenToAscii16(html& a);//ASCII值转化为十六进制
string Dange(int a);//ASCII值转化为十六进制

int main() {
    int High, Wide, high, wide;
    int H, W;//区块数
    string data;
    html dataa;
    cin >> Wide >> High >> wide >> high;
    H = High / high;
    W = Wide / wide;
    vector<vector<string> > object(High);//接受字符串数据
    vector<vector<html> > change10(High);//将字符串数据转化为可识别十进制数
    //输入HTML颜色表信息
    for (int i = 0;i < High;i++)
        for (int j = 0;j < Wide;j++) {
            cin >> data;
            object[i].push_back(data);
        }

    //16进制转10进制
    for (int i = 0;i < High;i++)
        for (int j = 0;j < Wide;j++) {
            dataa = change(object[i][j]);
            change10[i].push_back(dataa);
        }
    //分块
    vector<vector<html> > show(H);
    for (int i = 0;i < (H);i++) {
        for (int j = 0;j < W;j++) {
            dataa = average(change10, i, j, high, wide);
            show[i].push_back(dataa);
        }
    }
    //清理空间
    vector<vector<string > >().swap(object);
    vector<vector<html > >().swap(change10);
    //输出
    string Kongge = "\\x20";
    string Huanhang = "\\x0A";
    unsigned int j;
    for (int i = 0;i < (High / high);i++) {
        for (j = 0;j < show[i].size();j++) {
            //若首个为默认背景色，重置；
            if (j == 0 && show[i][j].first == 0 && show[i][j].second == 0 && show[i][j].tired == 0) {
                    cout << "\\x1B\\x5B\\x30\\x6D";
                    cout << Kongge;
                    continue;               
            }
            else if (j > 0) {
                //若与上一个相同，跳过；
                if (show[i][j].first == show[i][j - 1].first && show[i][j].second == show[i][j - 1].second && show[i][j].tired == show[i][j - 1].tired) {
                    cout << Kongge;
                    continue;
                }
                //若为黑色背景色且于上一背景色不同，使用重置，若连续两次黑色背景色，后一次无动作
                if (show[i][j].first == 0 && show[i][j].second == 0 && show[i][j].tired == 0) {
                    cout << "\\x1B\\x5B\\x30\\x6D";
                    continue;
                }
            }
            //数据转化
            TenToAscii16(show[i][j]);
            show[i][j].head += Kongge;
            cout << show[i][j].head;
        }
        if (show[i][j-1].first != 0 && show[i][j-1].second != 0 && show[i][j-1].tired != 0) {//若行末背景色不为默认，重置
           cout << "\\x1B\\x5B\\x30\\x6D";
        }
        cout << Huanhang;
    }
    return 0;
}

html change(string& y) {
    html x;
    if (y.size() == 2) {
        x.first = change2(y, 1) * 17;
        x.second = x.tired = x.first;
    }
    else if (y.size() == 4) {
        x.first = change2(y, 1) * 17;
        x.second = change2(y, 2) * 17;
        x.tired = change2(y, 3) * 17;
    }
    else {
        x.first = change2(y, 1) * 16 + change2(y, 2);
        x.second = change2(y, 3) * 16 + change2(y, 4);
        x.tired = change2(y, 5) * 16 + change2(y, 6);
    }
    return x;
}

html average(vector<vector<html> >& a, int i, int j, int high, int wide) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    html p;
    i *= high;
    j *= wide;
    for (int x = 0;x < high;x++) {
        for (int y = 0;y < wide;y++) {
            sum1 += a[i + x][j + y].first;
            sum2 += a[i + x][j + y].second;
            sum3 += a[i + x][j + y].tired;
        }
    }
    p.first = sum1 / (high * wide);
    p.second = sum2 / (high * wide);
    p.tired = sum3 / (high * wide);
    return p;
}

int change2(string& x, int n) {
    if (x[n] >= 48 && x[n] <= 57)
        return x[n] - 48;
    else
        return x[n] - 87;
}

void TenToAscii16(html& a) {
    int Ascii16[3] = { 0 };
    int first = a.first, second = a.second, tired = a.tired;
    string fenhao = "\\x3B", m = "\\x6D", Ling = "\\x30";
    //第一个数
    for (int i = 2;first != 0;i--) {
        Ascii16[i] = first % 10;
        first /= 10;
    }
    for (int i = 0;i < 3;i++) {
        if (Ascii16[i] == 0)
            continue;
        a.head += Dange(Ascii16[i]);
    }
    if (Ascii16[0] == 0 && Ascii16[1] == 0 && Ascii16[2] == 0) {
        a.head += Ling;
    }
    Ascii16[0] = Ascii16[1] = Ascii16[2] = 0;
    a.head += fenhao;
    //第二个数
    for (int i = 2;second != 0;i--) {
        Ascii16[i] = second % 10;
        second /= 10;
    }
    for (int i = 0;i < 3;i++) {
        if (Ascii16[i] == 0)
            continue;
        a.head += Dange(Ascii16[i]);
    }
    if (Ascii16[0] == 0 && Ascii16[1] == 0 && Ascii16[2] == 0) {
        a.head += Ling;
    }
    Ascii16[0] = Ascii16[1] = Ascii16[2] = 0;
    a.head += fenhao;
    //第三个数
    for (int i = 2;tired != 0;i--) {
        Ascii16[i] = tired % 10;
        tired /= 10;
    }
    for (int i = 0;i < 3;i++) {
        if (Ascii16[i] == 0)
            continue;
        a.head += Dange(Ascii16[i]);
    }
    if (Ascii16[0] == 0 && Ascii16[1] == 0 && Ascii16[2] == 0) {
        a.head += Ling;
    }
    Ascii16[0] = Ascii16[1] = Ascii16[2] = 0;
    a.head += m;

}

string Dange(int a) {
    int b;
    b = a + 48;
    string c;
    switch (b) {
    case 48:c = "\\x30";break;
    case 49:c = "\\x31";break;
    case 50:c = "\\x32";break;
    case 51:c = "\\x33";break;
    case 52:c = "\\x34";break;
    case 53:c = "\\x35";break;
    case 54:c = "\\x36";break;
    case 55:c = "\\x37";break;
    case 56:c = "\\x38";break;
    case 57:c = "\\x39";break;
    }
    return c;
}