#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int isPrime(long long n)
{
     if (n == 1)
        return 0;
     if (n == 2)
        return 1;
     int sq = (int)ceil(sqrt(n));
     for (int i = 2; i <= sq; i++)
     {
         if(n % i == 0)
              return 0;
     }
     return 1;
}

vector<int> addToVect(vector<int> v, int n)
{
    int temp = n;
    for (int t = 3; t >= 0; t--)
    {
        temp /= (int)ceil(pow(10, t));
        temp = temp % 10;
        v.push_back(temp);
        temp = n;
    }
    return v;
}

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k];
    cout <<endl;
}

int vecToNum(vector<int> v)
{
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum = 10*sum + v[i];
    }
    return sum;
}

vector<int> determineSeq(vector<int> v1, vector<int> v2, vector<int> v3)
{
    int num1 = vecToNum(v1);
    int num2 = vecToNum(v2);
    int num3 = vecToNum(v3);
    vector<int> toRet;
    if((num2 - num1) == (num3 - num2))
    {
        for(int m = 0; m < 4; m++)
            toRet.push_back(v1[m]);
        for(int m = 0; m < 4; m++)
            toRet.push_back(v2[m]);
        for(int m = 0; m < 4; m++)
            toRet.push_back(v3[m]);
    }
    return toRet;
}

vector<int> getResult(vector<vector<int> > v)
{
    vector<int> temp;
    if(v.size() < 3)
        return temp;

    for(int i = 0; i <= v.size() - 3; i++)
    {
        for (int j = i + 1; j <= v.size() - 2; j++)
        {
            for (int k = j + 1; k <= v.size() - 1; k++)
            {
                temp = determineSeq(v[i], v[j], v[k]);
                if(temp.size() == 12)
                    return temp;
            }
        }
    }
    return temp;
}

int main()
{
    vector<vector<int> > primes;

    for (int i = 1000; i < 10000; i++)
    {
        if (isPrime(i))
        {
            vector<int> temp;
            temp = addToVect(temp, i);
            primes.push_back(temp);
        }
    }

    vector<int> sequence;
    bool found = false;
    int counter = 0;
    while (!found)
    {
        vector<vector<int> > temp;
        vector<int> indices;
        indices.push_back(0);
        temp.push_back(primes[0]);
        int nums[10] = {0};
        for (int s = 0; s < 4; s++)
            nums[temp[0][s]]++;

        for (int k = 1; k < primes.size(); k++)
        {
            int numsTemp[10] = {0};
            for (int l = 0; l < 4; l++)
                numsTemp[primes[k][l]]++;

            bool numsEqual = true;
            for (int j = 0; j < 10; j++)
            {
                if(numsTemp[j] != nums[j])
                {
                    numsEqual = false;
                    break;
                }
            }

            if (numsEqual)
            {
                temp.push_back(primes[k]);
                indices.push_back(k);
            }
        }
        sequence = getResult(temp);
        if (sequence.size() > 0 && sequence[0] != 1)
            found = true;
        else
        {
            for(int s = indices.size() - 1; s >= 0; s--)
                primes.erase(primes.begin() + indices[s]);
        }
    }
    printV(sequence);
    return 0;
}
