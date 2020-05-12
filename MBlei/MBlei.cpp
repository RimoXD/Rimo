#include <iostream>
#include <vector>
using namespace std;

class Fract;
template <typename T>
class Array
{
public:
    int my_n;
    vector <T> array;
    Array(int n);
    void input(int n);
    T operator [](int n) {
        return array[n];
    }
    friend std::istream& operator>>(std::istream& in,Fract &a);
};



class Fract
{
public:
    int my_z, my_m;
    bool fh = true;
    Fract(int a, int b);
    Fract() {
        my_z = my_m = 0;
    }
    void show();
    Fract operator += (Fract a);
};


int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}

template<typename T>
Array<T>::Array(int n)
{
    my_n = n;
    array.resize(n);
}

template<typename T>
void Array<T>::input(int n)
{
    int i=0;
    for (i = 0;i < n;i++)
        cin >> array[i];
}


Fract::Fract(int a, int b)
{
    int i;
    if (a < 0)
    {
        fh = !fh;
        a = -a;
    }
    if (b < 0)
    {
        fh = !fh;
        b = -b;
    }
    if (b == 0)
    {
        cout << "error" << endl;
        exit(0);
    }
    if (a != 0 )
    {
        for (i = 2;i <= a && i <= b;i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                a /= i;
                b /= i;
                i = 2;
            }
        }
        my_z = a;
        my_m = b;
    }
    else
    {
        my_z = 0;
        my_m = 1;
    }
}

void Fract::show()
{
    if (fh)
    {
        if (my_z == 0 || my_m == 1)
            cout << my_z << endl;
        else
        {
            cout << my_z << "/" << my_m << endl;
        }
    }
    else
    {
        if (my_z == 0 || my_m == 1)
            cout << "-" << my_z << endl;
        else
        {
            cout << "-" << my_z << "/" << my_m << endl;
        }
    }
}

Fract Fract::operator+=(Fract a)
{
    if (this->fh == a.fh)
    {
        Fract b((this->my_z * a.my_m + this->my_m * a.my_z), this->my_m * a.my_m);
        this->my_z = b.my_z;
        this->my_m = b.my_m;
    }
    else {
        if(a.fh == false)
        {
            a.my_z = -a.my_z;
            Fract b((this->my_z * a.my_m + this->my_m * a.my_z), this->my_m * a.my_m);
            this->my_z = b.my_z;
            this->my_m = b.my_m;
            this->fh = b.fh;
        }
        else if (this->fh == false)
        {
            this->my_z = -this->my_z;
            Fract b((this->my_z * a.my_m + this->my_m * a.my_z), this->my_m * a.my_m);
            this->my_z = b.my_z;
            this->my_m = b.my_m;
            this->fh = b.fh;
        }
    }
    return *this;
}



std::istream& operator>>(std::istream& in, Fract &a)
{
    in >> a.my_z;
    in >> a.my_m;
    Fract b(a.my_z, a.my_m);
    a.my_z = b.my_z;
    a.my_m=b.my_m;
    a.fh = b.fh;
    return in;
}
