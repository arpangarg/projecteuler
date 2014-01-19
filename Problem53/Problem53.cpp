#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k] << " ";
    cout << endl;
}

int main()
{
    vector<vector<int> > pascal;
    vector<int> init;
    init.push_back(0);
    pascal.push_back(init);
    init[0] = 1;
    pascal.push_back(init);
    init.push_back(2);
    init.push_back(1);
    pascal.push_back(init);
    int count = 0;
    for (int n = 2; n < 100; n++)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int i = 0; i < n; i++)
        {
            int sum = pascal[n][i] + pascal[n][i+1];
            if (pascal[n][i] == 0 || pascal[n][i+1] == 0 || sum > 1000000)
            {
                count++;
                temp.push_back(0);
            }
            else
                temp.push_back(sum);
        }
        temp.push_back(1);
        pascal.push_back(temp);
    }
    cout << count;
    return 0;
}
