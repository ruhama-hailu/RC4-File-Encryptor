#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void rc4(vector<unsigned char>& data, string key)
{
    unsigned char S[256];

    for (int i = 0; i < 256; i++)
        S[i] = i;

    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % key.length()]) % 256;
        swap(S[i], S[j]);
    }

    int i = 0;
    j = 0;

    for (int k = 0; k < data.size(); k++)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);

        int keyByte = S[(S[i] + S[j]) % 256];

        data[k] = data[k] ^ keyByte;
    }
}

int main()
{
    string key = "mysecretkey";

    ifstream file("file.txt", ios::binary);

    vector<unsigned char> data(
        (istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>()
    );

    file.close();

    rc4(data, key);

    ofstream output("file.txt", ios::binary);
    output.write((char*)data.data(), data.size());
    output.close();

    cout << "File encrypted!" << endl;

    return 0;
}
