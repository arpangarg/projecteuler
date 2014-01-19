#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

vector<int> triangle;
int tsize;

int level(int i)
{
    return ceil((-1 + sqrt(1 + 8*i))/2);
}

int maxSum(int root)
{
    int maxLeft, maxRight, left, right;
    left = root + level(root);
    right = root + level(root) + 1;
    if(right > tsize - 1 && left > tsize - 1)
    {
        return triangle[root];
    }
    else if(left + level(left) > tsize - 1)
    {
        maxRight = triangle[right];
        maxLeft = triangle[left];
    }
    else
    {
        maxRight = maxSum(right);
        maxLeft = maxSum(left);
    }
    if (maxRight > maxLeft)
        return triangle[root] + maxRight;
    else
        return triangle[root] + maxLeft;
}

int main()
{
    int temp;

    triangle.push_back(0);
    ifstream inFile;
    inFile.open("data.txt");
    while (!inFile.eof())
    {
        inFile >> temp;
        triangle.push_back(temp);
    }
    inFile.close();

    tsize = triangle.size();
/*
    int left, right;
    int sum = 0;
    int i = 1;
    while (i < triangle.size() - 1)
    {
        sum += triangle[i]; cout << triangle[i] << endl;
        left = triangle[i + level(i)];
        right = triangle[i + level(i) + 1];
        if (left > right)
            i += level(i);
        else
            i += level(i) + 1;
    }
*/
    cout << maxSum(1);
    return 0;
}
