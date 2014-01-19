#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

void printV(vector<int> v)
{
    for (int k = 0; k < v.size(); k++)
        cout << v[k] << endl;
}

int main()
{
    string input;
    ifstream inFile;
    inFile.open("data.txt");
    inFile >> input;
    inFile.close();

    int inSize = input.size();
    int i = 0;
    string temp;
    vector<int> message;
    while (i < inSize)
    {
        while(input[i] != ',')
        {
            temp += input[i];
            i++;
        }
        i++;
        int val = atoi(temp.c_str());
        message.push_back(val);
        temp = "";
    }

    vector<int> decrypted;
    int numSpaces = 0;
    int key[3] = {97, 97, 97};
    for (key[0] = 97; key[0] < 123; key[0]++)
    {
        for (key[1] = 97; key[1] < 123; key[1]++)
        {
            for (key[2] = 97; key[2] < 123; key[2]++)
            {
                numSpaces = 0;
                decrypted.clear();
                for(int k = 0; k < message.size(); k+=3)
                {
                    for(int j = k; j < k + 3; j++)
                    {
                        if (j < message.size())
                        {
                            int temp = message[j] ^ key[j - k];
                            if (temp > 126 || temp < 32)
                                break;
                            else
                            {
                                decrypted.push_back(temp);
                                if (temp == 32)
                                    numSpaces++;
                            }
                        }
                    }
                }
                if(decrypted.size() == message.size() && numSpaces > 200)
                {
                    int sum = 0;
                    for(int m = 0; m < decrypted.size(); m++)
                        sum += decrypted[m];
                    cout << sum;
                    return 0;
                }
            }
        }
    }
}
