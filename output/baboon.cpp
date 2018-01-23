#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream ifs;
ofstream ofs;
ofstream ofs_bw;
ofstream ofss;

struct pix
{
    char r;
	char g;
	char b;
} px;

char    Header[54];

char infile[]       =   "d:\\mitm302\\baboon.bmp";
char outfile[]     =   "d:\\mitm302\\baboon2.bmp";
char outfile_bw[]   =   "d:\\mitm302\\baboon_bw.bmp";
char image_data[]   =   "d:\\mitm302\\baboon_data.txt";

int main()
{

    ifs.open( infile, ios::in|ios::binary );
    ifs.read( (char*) (&Header),sizeof(Header) );

    ofs.open( outfile, ios::out|ios::binary);
    ofs.write( (char*) (&Header),sizeof(Header) );

    ofs_bw.open( outfile_bw, ios::out|ios::binary);
    ofs_bw.write( (char*) (&Header),sizeof(Header) );

    ofss.open( image_data, ios::out);

    while(!ifs.eof())
    {
        ifs.read( (char*) (&px),sizeof(px) );

        ofs.write( (char*) (&px),sizeof(px) );

		int avg = (int)((px.r + px.g + px.b)/3);

        ofss<<"Baboon.bmp: "<<(int)px.r<<", "<<(int)px.g<<", "<<(int)px.b<<"    "<<"Average: "<<(int)avg<<endl;

        px.r = px.g = px.b = avg;

        ofs_bw.write( (char*) (&px),sizeof(px) );
    }

    ifs.close();
    ofs.close();
    ofs_bw.close();
    ofss.close();

    return 0;
}
