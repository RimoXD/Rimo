
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream afile;
    ofstream bfile;
    int i,a,b;
    afile.open("a.txt");
    bfile.open("b.txt");
    if (afile.is_open())
    {
        afile.seekg(0, afile.end);
        vector <float> count(afile.tellg());
        cout << afile.tellg();
        afile.seekg(0, afile.beg);
        for (i = 0;afile;i++)
        {
            afile >> count[i];
        }
        i--;
        int a, b;
        for (a = 0;a < i;a++)
        {
            for (b = a;b < i;b++)
            {
                if (count[b] < count[a])
                {
                    float t = count[a];
                    count[a] = count[b];
                    count[b] = t;
                }
            }
        }
        for (a = 0;a < i;a++)
            bfile << count[a]<<" ";
        bfile.seekp(0, bfile.beg);
  /*      vector<char> bb(100);
        for (a = 0;bfile;a++)
            bfile >> bb[a];
        for (b = 0;b < a;b++)
            cout << bb[b];
 */
 }
    else
    {
        cout << "error" << endl;
        exit(1);
    }
    afile.close();
    bfile.close();
    return 0;
}
