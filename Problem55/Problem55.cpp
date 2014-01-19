#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int numDigits(int i)
{
    int numDig = 0;
    if (i == 0)
        return 0;
    while (i > 0)
    {
        i /= 10;
        numDig++;
    }
    return numDig;
}

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k];
    cout << endl;
}

vector<int> addToVect(vector<int> v, int n)
{
    int numDig = numDigits(n);
    int temp = n;
    for (int t = numDig - 1; t >= 0; t--)
    {
        temp /= (int)ceil(pow(10, t));
        temp = temp % 10;
        v.push_back(temp);
        temp = n;
    }
    return v;
}

vector<int> add(vector<int> vec1, vector<int> vec2) //same size vectors
{
    int temp;
    int carry = 0;
    for(int k = vec2.size() - 1; k >= 0; k--)
    {
        temp = vec1[k] + vec2[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
            if(k == 0)
            {
                vec1[0] = temp;
                vec1.insert(vec1.begin(), carry);
                return vec1;
            }
        }
        else
        {
            carry = 0;
        }
        vec1[k] = temp;
    }
    return vec1;
}

vector<int> revVec(vector<int> v)
{
    int a = 0, b = v.size() - 1;
    int temp;
    while(a < b)
    {
        temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        a++;
        b--;
    }
    return v;
}

int isPalin(vector<int> v)
{
    int a = 0, b = v.size() - 1;
    while(a < b)
    {
        if (v[a] != v[b])
            return 0;
        a++;
        b--;
    }
    return 1;
}

int main()
{
    int count = 0;
    for (int i = 2; i < 10000; i++)
    {
        vector<int> temp;
        temp = addToVect(temp, i);
        int j;
        for (j = 1; j < 50; j++)
        {
            vector<int> temp2 = revVec(temp);
            temp = add(temp, temp2);
            if (isPalin(temp))
                break;
        }
        if (j == 50)
            count++;
    }
    cout << count;
    return 0;
}
