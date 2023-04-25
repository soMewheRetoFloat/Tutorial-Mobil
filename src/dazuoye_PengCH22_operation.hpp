using namespace std;
#pragma pack(1)

int limi = 0;//    行动步数
int ligh = 0;//    已点亮灯数 

ResultType re = DARK;
Result RE;
void MAIN ();
void P1 ();
void P2 ();
void P3 ();
void P4 ();

void TURNLEFT (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh == game.map_run.num_lights) {
		re = LIGHT;
		return;
	}
	limi++;
	if(game.map_run.robot.dir==0)
	    game.map_run.robot.dir = Direction(2);
	else if(game.map_run.robot.dir==1)
	    game.map_run.robot.dir = Direction(3);
	else if(game.map_run.robot.dir==2)
	    game.map_run.robot.dir = Direction(1);
	else 
	    game.map_run.robot.dir = Direction(0);
	cout<<"TL succeed"<<endl; 
	auto_save();
}
void TURNRIGHT (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh == game.map_run.num_lights) {
		re = LIGHT;
		return;
	}
	limi++;
	if(game.map_run.robot.dir==0)
	    game.map_run.robot.dir = Direction(3);
	else if(game.map_run.robot.dir==1)
	    game.map_run.robot.dir = Direction(2);
	else if(game.map_run.robot.dir==2)
	    game.map_run.robot.dir = Direction(0);
	else 
	    game.map_run.robot.dir = Direction(1);
	cout<<"TR succeed"<<endl;
	auto_save();
}
void MOVE (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh == game.map_run.num_lights) {
		re = LIGHT;
		return;
	} 
	limi++;
	int xx = (game.map_run.robot.pos).x;
	int yy = (game.map_run.robot.pos).y;
	int hh = game.map_run.cells[xx][yy].height;
	if ((game.map_run.robot.dir)==0){
		if ((yy-1)<0)
		    cout <<"Move: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx][yy-1].height; 
		    if (h==hh){
		        game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx][yy-1].robot = true;
		    	(game.map_run.robot.pos).y = yy-1;
		    }
		    else 
		        cout <<"Move: You can not do this."<< endl;
	    }
	}
	else if ((game.map_run.robot.dir)==1){
		if ((yy+1)>=MAX_COL)
		    cout <<"Move: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx][yy+1].height; 
		    if (h==hh){
		        game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx][yy+1].robot = true;
		    	(game.map_run.robot.pos).y = yy+1;
		    }
		    else 
		        cout <<"Move: You can not do this."<< endl;
	    }
	}
	else if ((game.map_run.robot.dir)==2){
		if ((xx-1)<0)
		    cout <<"Move: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx-1][yy].height; 
		    if (h==hh){
		        game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx-1][yy].robot = true;
		    	(game.map_run.robot.pos).x = xx-1;
		    }
		    else 
		        cout <<"Move: You can not do this."<< endl;
	    }
	}
	else if ((game.map_run.robot.dir)==3){
		if ((xx+1)>=MAX_COL)
		    cout <<"Move: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx+1][yy].height; 
		    if (h==hh){
		        game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx+1][yy].robot = true;
		    	(game.map_run.robot.pos).x = xx+1;
		    }
		    else 
		        cout <<"Move: You can not do this."<< endl;
	    }
	}
	auto_save();
}
void JUMP (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	} 
	if (ligh == game.map_run.num_lights) {
		re = LIGHT;
		return;
	}
	limi++;
	int xx = (game.map_run.robot.pos).x;
	int yy = (game.map_run.robot.pos).y;
	int hh = game.map_run.cells[xx][yy].height;
	if ((game.map_run.robot.dir)==0){
		if ((yy-1)<0)
		    cout <<"Jump: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx][yy-1].height;
			if (h==0)
			     cout <<"Jump: You can not do this."<< endl;
		    else if ((h+1)==hh||(h-1)==hh){
		    	game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx][yy-1].robot = true;
		    	(game.map_run.robot.pos).y = yy-1;
		    }
		    else 
		        cout <<"Jump: You can not do this."<< endl;
	    }
	}
	else if ((game.map_run.robot.dir)==1){
		if ((yy+1)>=MAX_COL)
		    cout <<"Jump: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx][yy+1].height; 
		    if (h==0)
		        cout <<"Jump: You can not do this."<< endl;
		    else if ((h+1)==hh||(h-1)==hh){
		    	game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx][yy+1].robot = true;
		    	(game.map_run.robot.pos).y = yy+1;
		    }
		    else 
		        cout <<"Jump: You can not do this."<< endl;
	    }
	}
	else if ((game.map_run.robot.dir)==2){
		if ((xx-1)<0)
		    cout <<"Jump: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx-1][yy].height;
			if (h==0)
			    cout <<"Jump: You can not do this."<< endl; 
		    else if ((h+1)==hh||(h-1)==hh){
		    	game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx-1][yy].robot = true;
		    	(game.map_run.robot.pos).x = xx-1;
		    }
		    else 
		        cout <<"Jump: You can not do this."<< endl;
	    }
	}
	else if ((game.map_run.robot.dir)==3){
		if ((xx+1)>=MAX_COL)
		    cout <<"Jump: You can not do this."<< endl;
		else{
		    int h = game.map_run.cells[xx+1][yy].height;
			if (h==0)
			    cout <<"Jump: You can not do this."<< endl; 
		    else if ((h+1)==hh||(h-1)==hh){
		    	 game.map_run.cells[xx][yy].robot = false;
		        game.map_run.cells[xx+1][yy].robot = true;
		    	(game.map_run.robot.pos).x = xx+1;
		    }
		    else 
		        cout <<"Jump: You can not do this."<< endl;
	    }
	}
	auto_save();
}
void LIGHTT(){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh == game.map_run.num_lights) {
		re = LIGHT;
		return;
	}
	limi++;
	int xx = (game.map_run.robot.pos).x;
	int yy = (game.map_run.robot.pos).y;
	Cell* cceell = &game.map_run.cells[xx][yy];
	if (game.map_run.cells[xx][yy].light_id==0){
	    ligh++;
		game.map_run.cells[xx][yy].light_id=1;
		for(int i = 0; i < MAX_LIT; i++) {
			if(game.map_run.lights[i].pos.x == xx && game.map_run.lights[i].pos.y == yy) {
				game.map_run.lights[i].lighten=true;
				break;
			}
		}
	}
	else if (game.map_run.cells[xx][yy].light_id==-1)
	    cout << "Light "<<xx<<" "<<yy<< " : This position has no light." << endl;
	else if (game.map_run.cells[xx][yy].light_id==1)
	    cout << "Light "<<xx<<" "<<yy<< " : This light has been lightened." << endl;
	auto_save();
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
}
void MAIN (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
	limi++; 
	if (Op.count >0){
		int n = Op.procs[0].count;
	    for (int i = 0;i<n;i++){
		    int ls = Op.procs[0].ops[i];
		    if(ls==0)
		        TURNLEFT();
		    else if (ls==1)
			    TURNRIGHT();
		    else if (ls==2)
		        MOVE();
		    else if (ls==3)
		        JUMP();
		    else if (ls==4)
	            LIGHTT();
	        else if (ls==5)
		        MAIN();
	    	else if (ls==6) 
		        P1();
		    else if (ls==7)
		        P2();
	    	else if (ls==8)
		        P3();
	    	else if (ls==9)
	    	    P4();
	    }
	}
	else 
    	cout << "No required process" <<endl;
	auto_save();
	if (ligh==game.map_run.num_lights){
		re = LIGHT;
		return;
	}
	else if (limi>=game.limit){
	    re = LIMIT; 
	    return;
	}
	else {
		re = DARK; 
	    return;
	}
}
void P1 (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
	limi++;
	if (Op.count >1){
		int n = Op.procs[1].count;
	    for (int i = 0;i<n;i++){
		    int ls = Op.procs[1].ops[i];
		    if(ls==0)
		        TURNLEFT();
		    else if (ls==1)
			    TURNRIGHT();
		    else if (ls==2)
		        MOVE();
		    else if (ls==3)
		        JUMP();
		    else if (ls==4)
	            LIGHTT();
	        else if (ls==5)
		        MAIN();
	    	else if (ls==6) 
		        P1();
		    else if (ls==7)
		        P2();
	    	else if (ls==8)
		        P3();
	    	else if (ls==9)
	    	    P4();
	    }
	}
	else 
    	cout << "No required process" <<endl;
	auto_save();
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
}
void P2 (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
	limi++;
	if (Op.count >2){
		int n = Op.procs[2].count;
	    for (int i = 0;i<n;i++){
		    int ls = Op.procs[2].ops[i];
		    if(ls==0)
		        TURNLEFT();
		    else if (ls==1)
			    TURNRIGHT();
		    else if (ls==2)
		        MOVE();
		    else if (ls==3)
		        JUMP();
		    else if (ls==4)
	            LIGHTT();
	        else if (ls==5)
		        MAIN();
	    	else if (ls==6) 
		        P1();
		    else if (ls==7)
		        P2();
	    	else if (ls==8)
		        P3();
	    	else if (ls==9)
	    	    P4();
	    }
	}
	else 
    	cout << "No required process" <<endl;
	auto_save();
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
}
void P3 (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
	limi++;
	if (Op.count >3){
		int n = Op.procs[3].count;
	    for (int i = 0;i<n;i++){
		    int ls = Op.procs[3].ops[i];
		    if(ls==0)
		        TURNLEFT();
		    else if (ls==1)
			    TURNRIGHT();
		    else if (ls==2)
		        MOVE();
		    else if (ls==3)
		        JUMP();
		    else if (ls==4)
	            LIGHTT();
	        else if (ls==5)
		        MAIN();
	    	else if (ls==6) 
		        P1();
		    else if (ls==7)
		        P2();
	    	else if (ls==8)
		        P3();
	    	else if (ls==9)
	    	    P4();
	    }
	}
	else 
    	cout << "No required process" <<endl;
	auto_save();
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
}
void P4 (){
	if (limi>=game.limit){
		re = LIMIT;
		return;
	}
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
	limi++;
	if (Op.count >4){
		int n = Op.procs[4].count;
	    for (int i = 0;i<n;i++){
		    int ls = Op.procs[4].ops[i];
		    if(ls==0)
		        TURNLEFT();
		    else if (ls==1)
			    TURNRIGHT();
		    else if (ls==2)
		        MOVE();
		    else if (ls==3)
		        JUMP();
		    else if (ls==4)
	            LIGHTT();
	        else if (ls==5)
		        MAIN();
	    	else if (ls==6) 
		        P1();
		    else if (ls==7)
		        P2();
	    	else if (ls==8)
		        P3();
	    	else if (ls==9)
	    	    P4();
	    }
	}
	else 
    	cout << "No required process" <<endl;
	auto_save();
	if (ligh==game.map_run.num_lights){
	    re = LIGHT; 
	    return;
	}
}

bool running_or_not =false;

Result robot_run(const char * path){
	ifstream fin ;
	fin.open(path);
	if (!fin){
		cout << "Error: Fail to open file\n";
		running_or_not = false;
		RE.result = re;
		RE.steps = 0;
		return RE;
	}
	fin >> Op.count;
	running_or_not = true;
	for (int i = 0;i<Op.count;i++){
		fin >> Op.procs[i].count;
		for (int j = 0;j<Op.procs[i].count;j++){
			char zf[4];
			fin >> zf;
			if (strcmp(zf,"TL")==0)
				Op.procs[i].ops[j]=OpType(0);
			else if (strcmp(zf,"TR")==0)
			    Op.procs[i].ops[j]=OpType(1);
			else if (strcmp(zf,"MOV")==0)
			    Op.procs[i].ops[j]=OpType(2);
			else if (strcmp(zf,"JMP")==0)
			    Op.procs[i].ops[j]=OpType(3);
			else if (strcmp(zf,"LIT")==0)
			    Op.procs[i].ops[j]=OpType(4);
			else if (strcmp(zf,"MAIN")==0)
			    Op.procs[i].ops[j]=OpType(5);
			else if (strcmp(zf,"P1")==0)
			    Op.procs[i].ops[j]=OpType(6);
			else if (strcmp(zf,"P2")==0)
			    Op.procs[i].ops[j]=OpType(7);
			else if (strcmp(zf,"P3")==0)
			    Op.procs[i].ops[j]=OpType(8);
			else if (strcmp(zf,"P4")==0)
			    Op.procs[i].ops[j]=OpType(9);
		}
	}
	game.map_run = game.map_init;
	RE.result = DARK;
	RE.steps = 0;
	auto_save();
	MAIN();
	RE.result = re;
	RE.steps = limi;
	RE.steps--;
	re = DARK;
	ligh = 0;
	limi = 0;
	return RE;
}
