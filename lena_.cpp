#include <iostream>
#include <fstream>

using namespace std;

ifstream ifs;
ofstream ofs, ofsbw;
ofstream t1, t2, t3;

struct pix
{
    char r;
    char g;
    char b;
} px;

struct blackwhite
{
    char l1;
    char l2;
    char l3;
} bw;


char Header[54];

char lena_ip[]      =   "d:\\lena.bmp";
char lena_op[]      =   "d:\\lena2.bmp";
char lena_bw[]      =   "d:\\lena3.bmp";

char header_info[]  =   "d:\\lena_header.txt";
char image_info[]   =   "d:\\lena_imageinfo.txt";
char image_data[]   =   "d:\\lena_data.txt";

int main()
{
    ifs.open( lena_ip, ios::in|ios::binary );

    ofs.open( lena_op, ios::out|ios::binary );
    ofsbw.open( lena_bw, ios::out|ios::binary );

    t1.open( header_info, ios::out);
    t2.open( image_info, ios::out);
    t3.open( image_data, ios::out);

    ifs.read( (char*) (&Header),54 );

    ofs.write( (char*) (&Header),54 );
    ofsbw.write( (char*) (&Header),54 );

    t1.write( (char*) (&Header),54 );

    while(!ifs.eof())
    {
        ifs.read( (char*) (&px),sizeof(px) );
        ofs.write( (char*) (&px),sizeof(px) );

        t2.write( (char*) (&px),sizeof(px) );

        t3<<"Red: "<<(int)px.r<<"\tGreen: "<<(int)px.g<<"\tBlue: "<<(int)px.b;

        int lum = (int)( (.21*px.r) + (.72*px.g) + (.07*px.b) );

        bw.l1 = bw.l2 = bw.l3 = lum;

        ofsbw.write( (char*) (&bw),sizeof(bw) );

        t3<<"\tLuminosity: "<<(int)lum<<endl;
    }

    ifs.close();
    ofs.close();
    ofsbw.close();

    t1.close();
    t2.close();
    t3.close();
    return 0;
}
