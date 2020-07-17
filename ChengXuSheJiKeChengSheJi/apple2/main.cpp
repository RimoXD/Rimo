#include <iostream>
#include <vector>
using namespace std;

int main() {
    int sum=0,num=0,E=0;//总数，掉落棵数，连续3颗掉落掉落组数
    int onesum=0;
    int N,m,data;
    int count=0;//计数器
    cin>>N;
    vector<vector<int> > object(N);
    vector<bool> isfall(N, false);
    //输入数据
    for(int i=0;i<N;i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> data;
            object[i].push_back(data);
        }
    }
    //遍历
    for(int i=0;i<N;i++) {
        onesum = object[i][0];
        for (int j = 1; j < object[i].size(); j++) {
            if (object[i][j] > 0 && object[i][j] < onesum) {
                onesum = object[i][j];
                isfall[i] = true;
            } else if (object[i][j] <= 0)
                onesum += object[i][j];
        }
        sum += onesum;
    }
    //记录掉果情况
    for(int i=0;i<N;i++) {
        if (isfall[i]) {
            count++;
            num++;
            if (count % 3 == 0) {
                E++;
                count--;
            }
        } else {
            count = 0;
        }
    }
    if(isfall[N-2]&&isfall[N-1]&&isfall[0])
        E++;
    if(isfall[N-1]&&isfall[1]&&isfall[0])
        E++;


    cout<<sum<<" "<<num<<" "<<E<<endl;
    return 0;
}
