#include<iostream>
#include<fstream>
#include<cmath>
#include<stdlib.h>
#include<cstring>

#define MAX_OPS 12
#define MAX_PROCS 5
#define MAX_ROW 10
#define MAX_COL 10
#define MAX_LIT 20
#define MAX_PATH_LEN 200

struct Position {
int x, y; // x for COL，y for ROW 
};

enum Direction {
UP, DOWN, LEFT, RIGHT 
};

struct Robot {
Position pos; // robot position
Direction dir; // robot direction
};

struct Light {
Position pos; // light position
bool lighten; // whether lighten or not
};


//single cell
struct Cell {
int height; // cell hight
int light_id; // whether light and light condition
bool robot; // true/false respectively indicate robot here/not here
};

//operation
enum OpType {
TL, TR, MOV, JMP, LIT, CALL
};

//process
struct Proc {
    OpType ops[MAX_OPS];
    int count; //sum of efficient operation MAX_OPS=12
};

//operation sequence
struct OpSeq {
// procs[0] for MAIN，procs[1] for P1
Proc procs[MAX_PROCS]; 
int count; // sum of efficient process MAX_PROCS=5
};

struct Map {
Cell cells[MAX_ROW][MAX_COL]; //map ondex
int row, col; // efficient row and column  MAX_ROW=10,MAX_COL=10

Light lights[MAX_LIT]; //MAX_LIT=20
int num_lights,num_procs; // efficent light and process in certain map 

Robot robot; //ONLY ONE
int op_limit[MAX_PROCS]; //limit for certain operation
};

struct Game {
char map_name[MAX_PATH_LEN]; // map path for fin
Map map_init; // initial condition
Map map_run; // running condition
char save_path[MAX_PATH_LEN]; //path for autosave
int auto_save_id; // autosave identity as an interger
int limit; // prevent game crashing
};

Game game; // ONE AND ONLY
OpSeq Op;

enum ResultType {
LIGHT, // result 1 all lights lighten
LIMIT, // result 2 operation limit
DARK   // result 3 "main" done
};

struct Result {
int steps; // record total steps
ResultType result; // record result 
};
int templimit=60;