#ifndef BIGINT_MULTIPLY_H
#define BIGINT_MULTIPLY_H

#include <QVector>

QVector<int> BigInt_multiply(int a, int b)
{
    int aa[10] = { 0 }, bb[10] = { 0 };
    int ai, bi, i, j;

    //将a,b存入数组中
    for (ai = 0;a != 0;ai++)
    {
        aa[ai] = a % 10;
        a /= 10;
    }
    for (bi = 0;b != 0;bi++)
    {
        bb[bi] = b % 10;
        b /= 10;
    }

    //做乘法,得出n*m行结果
    QVector <QVector <int> > c(bi, QVector<int>(ai));
    for (i = 0;i < bi;i++)
    {
        for (j = 0;j < ai;j++)
        {
            c[i][j] = bb[i] * aa[j];
        }
    }

    //将每一行结果相加
    QVector <int> result(ai + bi, 0);
    for (i = 0;i < bi;i++)
    {
        for (j = 0;j < ai;j++)
        {
            result[i + j] += c[i][j];
        }
    }

    //进位
    for (i = 0;i < (ai + bi - 1);i++)
    {
        result[i + 1] += (result[i] / 10);
        result[i] %= 10;
    }

    //反序
    QVector <int> presult(result);
    for (i = 0;i < (ai + bi);i++)
    {
        if(result[ai+bi-1]!=0)
        result[i] = presult[ai + bi - i-1];
        else
        {
           // result[i] = presult[ai + bi - i - 2];  越界点
            if (i == (ai + bi - 1))
            {
                result.pop_back();
                break;
            }
            result[i] = presult[ai + bi - i - 2];
        }
    }

    return result;
}

QVector<int> BigInt_multiply(QVector<int> a, int b)
{
    int bb[10] = { 0 };
    int ai, bi, i, j;

    //将a,b反序存入数组中
    QVector <int> pa(a);
    ai = a.size();
    for (i = 0;i < a.size();i++)
    {
        a[i] = pa[ai - i - 1];
    }
    for (bi = 0;b != 0;bi++)
    {
        bb[bi] = b % 10;
        b /= 10;
    }

    //做乘法,得出n*m行结果
    QVector <QVector <int> > c(bi, QVector<int>(ai));
    for (i = 0;i < bi;i++)
    {
        for (j = 0;j < ai;j++)
        {
            c[i][j] = bb[i] * a[j];
        }
    }

    //将每一行结果相加
    QVector <int> result(ai + bi, 0);
    for (i = 0;i < bi;i++)
    {
        for (j = 0;j < ai;j++)
        {
            result[i + j] += c[i][j];
        }
    }

    //进位
    for (i = 0;i < (ai + bi - 1);i++)
    {
        result[i + 1] += (result[i] / 10);
        result[i] %= 10;
    }

    //反序
    QVector <int> presult(result);
    for (i = 0;i < (ai + bi);i++)
    {
        if (result[ai + bi - 1] != 0)
            result[i] = presult[ai + bi - i - 1];
        else
        {
            if (i == (ai + bi - 1))
            {
                result.pop_back();
                break;
            }
            result[i] = presult[ai + bi - i - 2];
        }
    }

    return result;
}

QVector<int> BigInt_multiply(QVector<int> a, QVector<int> b)
{
    int ai, bi, i, j;

    //将a,b反序存入数组中
    QVector <int> pa(a);
    ai = a.size();
    for (i = 0;i < a.size();i++)
    {
        a[i] = pa[ai - i - 1];
    }
    QVector <int> pb(b);
    bi = b.size();
    for (i = 0;i < b.size();i++)
    {
        b[i] = pb[bi - i - 1];
    }

    //做乘法,得出n*m行结果
    QVector <QVector <int> > c(bi, QVector<int>(ai));
    for (i = 0;i < bi;i++)
    {
        for (j = 0;j < ai;j++)
        {
            c[i][j] = b[i] * a[j];
        }
    }

    //将每一行结果相加
    QVector <int> result(ai + bi, 0);
    for (i = 0;i < bi;i++)
    {
        for (j = 0;j < ai;j++)
        {
            result[i + j] += c[i][j];
        }
    }

    //进位
    for (i = 0;i < (ai + bi - 1);i++)
    {
        result[i + 1] += (result[i] / 10);
        result[i] %= 10;
    }

    //反序
    QVector <int> presult(result);
    for (i = 0;i < (ai + bi);i++)
    {
        if (result[ai + bi - 1] != 0)
            result[i] = presult[ai + bi - i - 1];
        else
        {
            if (i == (ai + bi - 1))
            {
                result.pop_back();
                break;
            }
            result[i] = presult[ai + bi - i - 2];
        }
    }

    return result;
}

#endif // BIGINT_MULTIPLY_H
