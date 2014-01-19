#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> add(vector<int> vec1, vector<int> vec2) //same size vectors
{
    int temp;
    int carry = 0;
    int vecSize = vec1.size();
    for(int k = 0; k < vecSize; k++)
    {
        temp = vec1[k] + vec2[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
            if (k == vecSize - 1)
            {
                vec1.push_back(carry);
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

void printV(vector<int> fact)
{
    for(int m = fact.size() - 1; m >= 0; m--)
        cout << fact[m];
    cout << endl;
}

int main()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> total;

    v1.push_back(1);
    v2.push_back(1);
    int dig = 1;
    int term = 2;
    while (dig < 1000)
    {
        int leadZeros = v2.size() - v1.size();
        for(int m = 0; m < leadZeros; m++)
        {
            v1.push_back(0);
        }
        total = add(v2, v1);
        v1 = v2;
        v2 = total;
        term++;
        dig = v2.size();
    }

    cout << term;

    return 0;
}
