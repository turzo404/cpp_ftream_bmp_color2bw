#include <iostream>
#include <fstream>

using namespace std;

ifstream ifs;
ofstream ofs, ofsbw, ofspv;

struct pix
{
    char r;
    char g;
    char b;
} px;

char Header[54];

char lena_ip[]      =   "d:\\mitm302\\lena_ip.bmp";
char lena_op[]      =   "d:\\mitm302\\lena_op.bmp";
char lena_bw[]      =   "d:\\mitm302\\lena_bw.bmp";
char lena_pixVal[]  =   "d:\\mitm302\\lena_pixVal.txt";

int main()
{

    ifs.open( lena_ip, ios::in|ios::binary );
    ofs.open( lena_op, ios::out|ios::binary );
    ofsbw.open( lena_bw, ios::out|ios::binary );
    ofspv.open( lena_pixVal, ios::out );

    ifs.read( (char*) (&Header),sizeof(Header) );
    ofs.write( (char*) (&Header),sizeof(Header) );
    ofsbw.write( (char*) (&Header),sizeof(Header) );

    while(!ifs.eof())
    {
        ifs.read( (char*) (&px),sizeof(px) );
        ofs.write( (char*) (&px),sizeof(px) );

        int avg = (int)((px.r + px.g + px.b)/3);

        ofspv<<"Red: "<<(int)px.r<<" Green: "<<(int)px.g<<" Blue: "<<(int)px.b<<"    Average: "<<(int)avg<<endl;

        px.r = px.g = px.b = avg;

        ofsbw.write( (char*) (&px),sizeof(px) );
    }

    ifs.close();
    ofs.close();
    ofsbw.close();
    ofspv.close();

    return 0;
}
