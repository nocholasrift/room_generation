
/*
* Code to generate rooms for Hell or Highwater
*/

#define NUM_ROOMS 10
#define GRID_SIZE 100

#define North 1
#define East  2
#define South 3
#define West  4

#include <stdio.h> 
#include <stdlib.h> 
#include <random>
#include <iostream>
#include <time.h> 
using namespace std;

struct room{
	int doors[4] = {0,0,0,0};
	int connections[4] = {-1,-1,-1,-1};
	int size[2] = {5,5};
	int pos[2];
	int availableDoors = 0;

}; typedef struct room room_t;

struct floor{
	room_t rooms[NUM_ROOMS];
	// spawn room
	int startRoom;
	// "boss" room
	int endRoom;

}; typedef struct floor floor_t;

floor_t level;
char grid[GRID_SIZE][GRID_SIZE];

void initialize_rooms(){
	srand(time(0));
	for(room_t r : level.rooms){
		for(int i = 0; i < 4; i++){
			r.doors[i] = rand() % 2;
			cout << r.doors[i] << " ";
			r.availableDoors += r.doors[i];
		}
		if(r.availableDoors == 0)
		cout << endl;
	}
}

void generate(){
	random_device rd;
    mt19937 e(rd());
	uniform_int_distribution<int> dist(0, NUM_ROOMS);

	for(int i = 0; i < NUM_ROOMS; i++)
		cout << level.rooms[i].availableDoors << endl;

//		cout << dist(e) << endl;
}

int main(){
	// initialize_rooms();
	generate();
	return 0;
}