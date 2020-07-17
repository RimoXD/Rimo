#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M;//棵数和轮数
    int T,P,k;//总数，编号，个数
    int date,max=0,othmax=0,imax=1,sum=0;
    cin>>N>>M;
    vector< vector<int> > object(N);//建立矩阵
    for(int i=0;i<N;i++)
        cin>>date;
        for(int j=0;j<M+1;j++){
            object[i].push_back(date);
        }
    //定义第一组为最大
    for(int i=1;i<M+1;i++)
        max+=object[0][i];
    //遍历查找
    for(int i=0;i<N;i++) {
        for (int j = 0; j < M + 1; j++){
            sum += object[i][j];
            if(j>=1){
                othmax+=object[i][j];
            }
        }
        if(othmax<max){
            max=othmax;
            imax=i+1;
        }
        othmax=0;
    }
    cout<<sum<<" "<<imax<<" "<<-max<<endl;
    return 0;
}
