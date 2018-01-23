#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream iFile;
    char ch;
    iFile.open("D:\\mitm302\\lena\\lena_ip.bmp",ios::binary);
    ofstream oFile;
    oFile.open("D:\\mitm302\\lena\\lena3.bmp",ios::binary);

    int fs[54];
    int tfs[54];
    int pixel[512][512];
    if(iFile.is_open() && oFile.is_open())
    {
        for(int i=0; i<54; i++)
        {
            iFile.get(ch);
            fs[i]=ch;
            cout<<fs[i]<<"  ";
            char p;
            p=fs[i];
            oFile<<p;

        }

        for(int w=0; w<512; w++)
        {
            for(int h=0; h<512; h++)
            {
                iFile.get(ch);
                pixel[w][h]=ch;
                char pi=pixel[w][h];
                oFile<<pi;
            }
        }
        oFile.close();
        iFile.close();
    }

    else cout << "Unable to open file"<<endl;

    return 0;
}
