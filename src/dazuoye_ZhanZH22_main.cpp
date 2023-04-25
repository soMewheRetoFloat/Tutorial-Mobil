#include "dazuoye_settings.hpp"
#include "dazuoye_LiaoZY22_paint.hpp"
#include "dazuoye_PengCH22_operation.hpp"

using namespace std;
#pragma pack(1)

void status(Game game) //interaction segment STATUS
{
            cout<<"Map Name: "<<game.map_name<<endl;
            cout<<"Autosave: "<<game.save_path<<endl;
            cout<<"Step Limit: "<<templimit<<endl;
            for(int i=0;i<game.map_run.row;i++) { //output data depend on every block
                for(int j=0;j<game.map_run.col;j++) {
                    if(game.map_run.cells[j][i].height==0) {
                        cout<<"\e[0m ";
                    }
                    else if(game.map_run.cells[j][i].robot==1) {

                        if(game.map_run.cells[j][i].light_id==1) {
                            cout<<"\e[91;103;1m"<<game.map_run.cells[j][i].height;
                        }
                        else if(game.map_run.cells[j][i].light_id==0) {
                            cout<<"\e[91;104;1m"<<game.map_run.cells[j][i].height;
                        }
                        else if(game.map_run.cells[j][i].light_id==-1) {
                            cout<<"\e[91;100;1m"<<game.map_run.cells[j][i].height;
                        }
                    }
                    else {
                        if(game.map_run.cells[j][i].light_id==1) {
                            cout<<"\e[92;103;1m"<<game.map_run.cells[j][i].height;
                        }
                        else if(game.map_run.cells[j][i].light_id==0) {
                            cout<<"\e[92;104;1m"<<game.map_run.cells[j][i].height;
                        }
                        else if(game.map_run.cells[j][i].light_id==-1) {
                            cout<<"\e[92;100;1m"<<game.map_run.cells[j][i].height;
                        }
                    }
                    if(j==(game.map_run.col-1)) {
                        cout<<"\e[0m"<<endl;
                    }
                }
            }
            cout<<"\e[0m";
            if(game.map_run.robot.dir==UP) {cout<<"Robot is facing up."<<"\e[0m"<<endl;}
            else if(game.map_run.robot.dir==DOWN) {cout<<"Robot is facing down."<<"\e[0m"<<endl;}
            else if(game.map_run.robot.dir==LEFT) {cout<<"Robot is facing left."<<"\e[0m"<<endl;}
            else if(game.map_run.robot.dir==RIGHT) {cout<<"Robot is facing right."<<"\e[0m"<<endl;}
            cout<<"Proc Limit: ";
            if(game.map_run.num_procs > 0) {
                cout<<"[";
            }
            for(int p=0;p<game.map_run.num_procs;p++) {
                cout<<game.map_run.op_limit[p];
                if(p==(game.map_run.num_procs-1)) {
                    cout<<"]"<<endl;
                }
                else {
                    cout<<", ";
                }
            }
}

void status_end(Game game)
{
    if (RE.result == LIGHT) {cout<<"LIGHT"<<endl;}
    else if (RE.result == LIMIT) {cout<<"LIMIT"<<endl;}
    else if (RE.result == DARK) {cout<<"DARK"<<endl;}
    cout<<"Step(s) used: "<<RE.steps<<endl;

    for(int i=0;i<game.map_run.row;i++) { //output data depend on every block
        for(int j=0;j<game.map_run.col;j++) {
            if(game.map_run.cells[j][i].height==0) {
                cout<<"\e[0m ";
            }
            else if(game.map_run.cells[j][i].robot==1) {
                if(game.map_run.cells[j][i].light_id==1) {
                    cout<<"\e[91;103;1m"<<game.map_run.cells[j][i].height;
                }
                else if(game.map_run.cells[j][i].light_id==0) {
                    cout<<"\e[91;104;1m"<<game.map_run.cells[j][i].height;
                }
                else if(game.map_run.cells[j][i].light_id==-1) {
                    cout<<"\e[91;100;1m"<<game.map_run.cells[j][i].height;                    
                }
            }
            else {
                if(game.map_run.cells[j][i].light_id==1) {
                    cout<<"\e[92;103;1m"<<game.map_run.cells[j][i].height;
                }
                else if(game.map_run.cells[j][i].light_id==0) {
                    cout<<"\e[92;104;1m"<<game.map_run.cells[j][i].height;
                }
                else if(game.map_run.cells[j][i].light_id==-1) {
                    cout<<"\e[92;100;1m"<<game.map_run.cells[j][i].height;
                }
            }
            if(j==(game.map_run.col-1)) {
                cout<<"\e[0m"<<endl;
            }
        }
    }
    cout<<"\e[0m";

    if(game.map_run.robot.dir==UP) {cout<<"Robot is facing up."<<"\e[0m"<<endl;}
    else if(game.map_run.robot.dir==DOWN) {cout<<"Robot is facing down."<<"\e[0m"<<endl;}
    else if(game.map_run.robot.dir==LEFT) {cout<<"Robot is facing left."<<"\e[0m"<<endl;}
    else if(game.map_run.robot.dir==RIGHT) {cout<<"Robot is facing right."<<"\e[0m"<<endl;}

    RE.steps = 0;
}

void initialize(Game &game)
{
    ifstream mapdata_in;//input files
    mapdata_in.open(game.map_name); 
    if(!mapdata_in.is_open()) {
        memset(game.map_name,'\0',sizeof(game.map_name)); //fin failed
        cout<<"Error: No such file in repository"<<endl;
    }
    else {
        cout<<"You're going to open: "<<game.map_name<<endl;
        memset(&game.map_init,0,sizeof(Map));
        mapdata_in>>game.map_init.row>>game.map_init.col
        >>game.map_init.num_lights>>game.map_init.num_procs; //4 index
        if(game.map_init.num_lights > MAX_LIT || game.map_init.num_lights > (game.map_init.row*game.map_init.col)
        || game.map_init.row > MAX_ROW || game.map_init.col > MAX_COL || game.map_init.num_procs > MAX_PROCS) {
            cout << "Error: Illegal map loading" << endl;
            return;
        }
        for(int i=0;i<game.map_init.row;i++) { 
            for(int j=0;j<game.map_init.col;j++) {
                mapdata_in>>game.map_init.cells[j][i].height; //setting height
                game.map_init.cells[j][i].light_id=-1; //light judgement
            }
        }
                
        for(int l=0;l<game.map_init.num_lights;l++) { //fin lights
            mapdata_in>>game.map_init.lights[l].pos.x>>game.map_init.lights[l].pos.y;
            //attention:bool has already been initialized to 0
            int lx=game.map_init.lights[l].pos.x,ly=game.map_init.lights[l].pos.y;
            if(game.map_init.lights[l].lighten) {
                game.map_init.cells[lx][ly].light_id=1; //change light. light off:“0” light on:“1”
            }
            else {
                game.map_init.cells[lx][ly].light_id=0;
            }
        }

        for(int p=0;p<game.map_init.num_procs;p++) {
            mapdata_in>>game.map_init.op_limit[p]; //max process
            if(game.map_init.op_limit[p] > MAX_OPS) {
                cout << "Error: Illegal map loading" << endl;
                return;
            }
        }

        mapdata_in>>game.map_init.robot.pos.x>>game.map_init.robot.pos.y; //robot position
        int rx=game.map_init.robot.pos.x,ry=game.map_init.robot.pos.y;
        game.map_init.cells[rx][ry].robot=true; //robot existence
        int temp=0;
        mapdata_in>>temp; //mamorize direction
        switch (temp)    //0up 1down 2left 3right
        {
        case 1:
            game.map_init.robot.dir=DOWN;
            break;
        case 2:
            game.map_init.robot.dir=LEFT;
            break;
        case 3:
            game.map_init.robot.dir=RIGHT;
            break;
        case 0:
            game.map_init.robot.dir=UP;
            break;
        default:
            cout<<"Error: No such direction"<<endl;
            return;
                }

    }
    mapdata_in.close();
    game.map_run = game.map_init;
    RE.steps = 0;
    RE.result = DARK;
}

void operation(Game game)
{
    ofstream mapdata_out; //output files
            char optemp[MAX_PATH_LEN];
            cin>>optemp;
            mapdata_out.open(optemp);
            if(mapdata_out.is_open()) {
            	cout<<"You're going to create option segment at "<<optemp<<".\n"<<endl;
                int line_nums; //.ops
                cin>>line_nums;
                if(line_nums>game.map_init.num_procs) {
                    cout<<"Error: out of program number limit\n\n";
                    return;
                }
                mapdata_out<<line_nums<<endl;
                for(int opss=0;opss<line_nums;opss++) {
                    int branch_nums; //operation number of a branch
                    cin>>branch_nums;
                    if(branch_nums>game.map_init.op_limit[opss]) {
                        cout<<"Error: out of option number limit\n\n";
                        return;
                    }
                mapdata_out<<branch_nums;
                char option1[20][10]={'\0'};
                for(int opsss=1;opsss<=branch_nums;opsss++) {
					cin>>option1[opsss];
                    mapdata_out<<" "<<option1[opsss];
                    if(opsss==branch_nums) {
                        mapdata_out<<endl;
                    }
                }
            }
            }
}

void running(Game game)
{
    char optemp_for_running[MAX_PATH_LEN];
    cin >> optemp_for_running;
    robot_run(optemp_for_running);
    if(running_or_not) {
    cout<<"RUN "<<optemp_for_running<<", result: ";
    }
}

int main()
{
    game.limit=61; //"for safety"
    game.auto_save_id=0; //autosave identification
    strcpy(game.save_path,"imgs/%4d.bmp");
    int id=0; //for latter usage
    for(int rss=0;rss<MAX_ROW;rss++) {
        for(int css=0;css<MAX_COL;css++) {
            game.map_init.cells[css][rss].light_id=-2; //no such cell light change to -2
        }
    }
    cout<<"\e[93;105;1mWelcome to CLiTBot by Wor1dRescu0r\e[0m"<<endl;
    cout<<"\e[96;50;1mFor detailed command list please press in '/help'\e[0m"<<endl;
    while(1) {
        cout<<"\e[96;50;1mCLiTBot command system"<<endl;
		cout<<"Please press in your command, attention that 'EXIT' is to end the game\e[0m"<<endl;
		char COMMAND[12];
        cin>>COMMAND;
        if (strcmp(COMMAND,"START")==0) //little stinger
        {
            cout<<"Start properly...Loading...\n\n";
        }
        if (strcmp(COMMAND,"EXIT")==0) { //exit command
            cout<<"See you next time!"<<endl;
            system("pause");
            return 0;
        }
        if(strcmp(COMMAND,"LOAD")==0) { //load command
            cin>>game.map_name; //map path
            initialize(game);
            status(game);
        }

        if((strcmp(COMMAND,"AUTOSAVE")==0)) { //autosave
            game.auto_save_id = 0;
            cin>>game.save_path;
            auto_save();
        }

        if((strcmp(COMMAND,"LIMIT")==0)) { 
            cin>>templimit; //change limit
            cout<<"Step limit change to "<<templimit<<"."<<endl;
            game.limit = templimit + 1;
			cout<<"\n";
        }

        if((strcmp(COMMAND,"STATUS")==0)) {
            status(game);
        }

        if(strcmp(COMMAND,"OP")==0) { //operation creating
            operation(game);
        }

        if(strcmp(COMMAND,"RUN")==0) { //running!
            running(game);
            if(running_or_not) {
                status_end(game);
                cout<<endl;
                cout<<"\e[96;50;1mpress in RESTART to try again, QUIT to quit\e[0m\n\n";
                while (1) {
                    char COMMAND_2[MAX_PATH_LEN];
                    cin >> COMMAND_2;
                    if (strcmp(COMMAND_2,"RESTART") == 0) {
                        initialize(game);
                        status(game);
                        RE.result = DARK;
                        RE.steps=0;
                        break;
                    }
                    else if (strcmp(COMMAND_2,"QUIT") == 0) {
                        RE.result = DARK;
                        RE.steps=0;
                        break;
                    }
                }
            }
            running_or_not = false;
        }

        if(strcmp(COMMAND,"/help")==0) {
            cout << "Command Table:" << endl;
            cout << "START: This do nothing actually." << endl;
            cout << "EXIT: Quit the game." << endl;
            cout << "LOAD: Load a certain map." << endl;
            cout << "AUTOSAVE: Change autosave mode (off or open), if open, press in imgs/%\e[93;105;1mn\e[0md.bmp, n for a number from 1 to 16(recommended)" << endl;
            cout << "Autosave mode is off by default." << endl;
            cout << "LIMIT: Change total step limitation." << endl;
            cout << "STATUS: Output current configuration." << endl;
            cout << "OP: Build an operation sequence." << endl;
            cout << "RUN: Run an operation sequence." << endl;
        }

        cout<<"\n";
    }
}
