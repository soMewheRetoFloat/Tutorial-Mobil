using namespace std;
#pragma pack(1)

struct BmpFileHeader{
    char id[2];
    int size;
    short res1,res2;
    int offset;
};
struct BmpInfoHeader{
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
struct Pixel{
	unsigned char b,g,r;
};
int transcode(char a){
	if((int)a>=0)
	return (int)a;
	else
	return (int)a+256;
}//to transfer char to wanted int
Pixel bmp[800][1000];
void save(const char * path)
{
	int w=1000,h=800;//width and height of the image
	int Row=game.map_run.row,Col=game.map_run.col;
	int Height=game.map_run.cells[0][0].height;
	for(int i=0;i<Row*Col;i++)
	if(game.map_run.cells[i%Col][i/Col].height>Height)
	Height=game.map_run.cells[i%Col][i/Col].height;//to get the maximum of height
	char d=(char)game.map_run.robot.dir+48;//to get the direction and use the corresponding bmp file
	char r[12]="robot";
	r[5]=d;
	strcpy(&r[6],".bmp");
    ofstream fbmp(path,ios::binary);//to input data to path
    ifstream fin(r,ios::binary);//to output data of robot
    BmpFileHeader bfh={{'B','M'},w*h*3+0x36,0,0,0x36};
    BmpInfoHeader bih={0x28,w,h,1,24,0,w*h*3};
    fbmp.write((char*)&bfh,sizeof(bfh));
    fbmp.write((char*)&bih,sizeof(bih));//to prepare for input
    for(int y=h-1;y>=0;y--)
   		for(int x=0;x<w;x++){
    		bmp[y][x].b=163;
    		bmp[y][x].g=73;
    		bmp[y][x].r=164;
		}//to set the background color to pink
	int width=900/(Row+Col),length=width*173/300;//to set suitable width and length of every block
	for(int h=1;h<=Height;h++){//to set color from the lowest tier
		int x[10000],y[10000];//to load the coordinates of every block's center
		int l0[10000],l1[10000];//to load the serial number of block whose light is off or on
		int num=0,num0=0,num1=0;//to record the number of specific blocks
		for(int i=0;i<Row*Col;i++)//to traverse all sites
		if(game.map_run.cells[i%Col][i/Col].height>=h){//to judge whether to make a input
			x[num]=50+width*(Row-i/Col+i%Col);
			y[num]=700-length*(Col+Row-1-i%Col-i/Col)-length*(h-1)/2;//to record the coordinates of blocks of each tier
			num++;
			if(game.map_run.cells[i%Col][i/Col].height==h)//to record the blocks whick is loaded with light
				for(int j=0;j<game.map_run.num_lights;j++)
					if(game.map_run.lights[j].pos.x==i%Col&&game.map_run.lights[j].pos.y==i/Col){
						if(game.map_run.lights[j].lighten){
							l1[num1]=num;
							num1++;
						}
						else{
							l0[num0]=num;
							num0++;
						}//to record the state(on is yellow and off is blue) of light
					}
		}
		for(int n=1;n<=num;n++){
			int x0=x[n-1],y0=y[n-1];//to get the coordinates of the block to be colored
			bool bright0=false,bright1=false;
			for(int i=0;i<num0;i++)
				if(n==l0[i])
					bright0=true;
			for(int i=0;i<num1;i++)
				if(n==l1[i])
					bright1=true;//to judge the color of the block(blue, yellow or grey)
			if(h==1)//the lowest tier is different from other tiers
				for(int i=x0-width;i<=x0+width+1;i++)
					for(int j=y0-length;j<=y0+length*5/4;j++){//to define the range of the area to be colored
						int i0=i-x0,j0=j-y0;//to get the relative coordinates
						if(((i-x0+width<2||x0+width+1-i<2)&&j>y0&&j<y0+length/4)||(i>=x0&&i<=x0+1&&j>y0+length&&j<y0+length*5/4)){//to color the black bottom
							bmp[j][i].b=0;
    						bmp[j][i].g=0;
    						bmp[j][i].r=0;
						}
						if(length*abs(i0)+width*abs(j0)<=length*width*51/50){//to limit the rhombus area
							if(abs(width*length-length*abs(i0)-width*abs(j0))<width*length/50){//to color the black frame
    							bmp[j][i].b=0;
    							bmp[j][i].g=0;
    							bmp[j][i].r=0;
							}
							else if(bright0){//to color the inside blue
								bmp[j][i].b=255;
								bmp[j][i].g=0;
								bmp[j][i].r=0;
							}
							else if(bright1){//to color the inside yellow
								bmp[j][i].b=0;
								bmp[j][i].g=255;
								bmp[j][i].r=255;
							}
							else{//to color the inside grey
								bmp[j][i].b=200;
    							bmp[j][i].g=200;
    							bmp[j][i].r=200;
							}
						}
					}
			else{
				for(int i=x0-width;i<=x0+width+1;i++)
					for(int j=y0-length;j<=y0+length*3/2;j++){
						int i0=i-x0,j0=j-y0;
						if(i>=x0-width+2&&i<x0&&-length*i0+width*j0>length*width*51/50&&-length*i0+width*j0<length*width*74/50){
							bmp[j][i].b=200;
    						bmp[j][i].g=200;
    						bmp[j][i].r=200;
						}//to color the left side light grey
						if(i<x0+width+2&&i>x0+1&&length*i0+width*j0>length*width*51/50&&length*i0+width*j0<length*width*74/50){
							bmp[j][i].b=165;
	    					bmp[j][i].g=165;
	    					bmp[j][i].r=165;
						}//to color the right side dark grey
						if(((i-x0+width<2||x0+width+1-i<2)&&j>y0&&j<y0+length/2)||(i>=x0&&i<=x0+1&&j>y0+length&&j<y0+length*3/2)){
							bmp[j][i].b=0;
   	 						bmp[j][i].g=0;
    						bmp[j][i].r=0;
						}//to color the middle line black
						if(length*abs(i0)+width*abs(j0)<=length*width*51/50){//to limit the rhombus area
							if(abs(length*width-length*abs(i0)-width*abs(j0))<length*width/50){//to color the black frame
    							bmp[j][i].b=0;
    							bmp[j][i].g=0;
    							bmp[j][i].r=0;
							}
							else if(bright0){//to color the inside blue
								bmp[j][i].b=255;
								bmp[j][i].g=0;
								bmp[j][i].r=0;
							}
							else if(bright1){//to color the inside yellow
								bmp[j][i].b=0;
								bmp[j][i].g=255;
								bmp[j][i].r=255;
							}
							else{//to color the inside grey
								bmp[j][i].b=200;
    							bmp[j][i].g=200;
    							bmp[j][i].r=200;
							}
						}
					}
			}
		}
	}
	int x1=game.map_run.robot.pos.x,y1=game.map_run.robot.pos.y;//to get the coordinates of the robot
	int x0=50+width*(Row-y1+x1),y0=700-length*(Col+Row-1-x1-y1)-length*(game.map_run.cells[x1][y1].height-1)/2;//to calculate the position of the robot
	char a[1355*16+6];
    fin.read(a,1355*16+6);//to get the data of the robot photo
    for(int i=x0-26;i<=x0+25;i++)
		for(int j=y0;j>=y0-103;j--){//to limit the area of the robot
   			int p=i-x0+26+52*(y0-j);//to calculate the serial number of the pixel
    		if(abs(transcode(a[p*4+53+1])-164)>40||abs(transcode(a[p*4+53+2])-73)>40||abs(transcode(a[p*4+53+3])-163)>40){//to exclude the pink color
    			bmp[j][i].b=a[p*4+53+1];
				bmp[j][i].g=a[p*4+53+2];
				bmp[j][i].r=a[p*4+53+3];
			}
		}
	for(int y=h-1;y>=0;y--)
	    for(int x=0;x<w;x++)
  			fbmp.write((char*)&bmp[y][x],3);//to input the data of the map
  	fbmp.close();
    fin.close();
}
void auto_save()
{
	if(strcmp(game.save_path,"OFF") == 0) {
		return;
	}
	else if(strlen(game.save_path)!=0 && game.save_path != "OFF"){//to check if the command is null
		char path[MAX_PATH_LEN];
		strcpy(path,game.save_path);
		char*a=strchr(path,'%');
		int n=(int)*(a+1)-48;
		for(int i=0;i<n;i++)
			a[i]='0';
		char s[10];
		itoa(game.auto_save_id,s,10);
		strcpy(a+n-strlen(s),s);
		strcpy(a+n,".bmp");//to joint the name of the file
		save(path);
		game.auto_save_id++;
	}	
}