#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#pragma pack(1)

struct BMPFileHeader
{
    char id[2];
    int size;
    short res1,res2;
    int offset;
};

struct BMPInfoHeader
{
    int hsize;
    int width;
    int height;
    short plane;
    short bpp;
    int compress;
    int isize;
    int hres;
    int vres;
    int palette;
    int icolor;
};

struct pixel
{
    unsigned char B,G,R;
};

int main() 
{
    /* 如果要键入指定行数的字符串，请使用循环和getline;
    ifstream fin1;
    fstream fout1;
    fout1.open("../../readme.md");
    for(int i=1;i<=9;i++) {
    fout1<<i<<endl;
    }
    fout1.close();
    

    fin1.open("../../readme.md");
    int n,id=-1;
    cin>>n;
    while(n>id&&(!fin1.eof())) {
        fin1>>id;
    }
    if(n==id) cout<<"有"<<endl;
    else cout<<"没有"<<endl;
    fin1.close();
    */

    int wid=800,hei=600;
    pixel p[wid][hei];
    ofstream fbmp("imgs/color.bmp",ios::binary);
    BMPFileHeader bfh{{'B','M'},(wid*3)*hei+0x36,0,0,0x36,};
    BMPInfoHeader bih{0x28,wid,hei,1,24,0,(wid*3)*hei,0,0,0,0};
    fbmp.write((char*)&bfh,sizeof(bfh));
    fbmp.write((char*)&bih,sizeof(bih));
    for(int y=hei-1;y>=0;y--) {
        for(int x=0;x<wid;x++) {
            p[x][y].R=255;
            p[x][y].G=255;
            p[x][y].B=255;
        }
    }
    for(int y=200;y>=50;y--) {
        for(int x=450;x<=600;x++) {
            p[x][y].R=23;
            p[x][y].G=156;
            p[x][y].B=123;
        }
    }
    for(int y=0;y<hei;y++) {
        for(int i=-1;i<=1;i++) {
            p[y+1][y].R=112;
            p[y+1][y].G=22;
            p[y+1][y].B=33;
        }
    }
    for(int y=hei-1;y>=0;y--) {
        for(int x=0;x<wid;x++) {
            fbmp.write((char*)&p[x][y],sizeof(pixel));
        }
        int pedding=3-(wid*3+3)%4;
        char temp='\0';
        for(int i=0;i<pedding;i++) {
            fbmp.write(&temp,sizeof(char));
        }
    }
    fbmp.close();
    return 0;
}