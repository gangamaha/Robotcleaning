//============================================================================
// Name        : robot.cpp
// Author      : gangadhar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
	ifstream inFile;
	inFile.open("input.txt");
	string linecount;
	int count=0;
	// Find total number of lines in input.txt
	while(getline(inFile,linecount)){
		++count;
	}
	// Next 2 lines set the file position from end to beginning of file
	inFile.clear();
	inFile.seekg(inFile.beg);
	int x,y,start,end;
	inFile >> x >> y;
	inFile.seekg(5);
	inFile >> start >> end;
	inFile.seekg(9);
	int i,j;
	string line;
	string dir;
	int ctr;
	int z,w;
	// Set the 2D array of x rows and y columns dynamically from input file
	int **arr=new int*[x];
	int **visited=new int*[x];
	for(z=0;z<x;z++){
		arr[z]=new int[y];
		visited[z]=new int[y];
		for(w=0;w<y;w++){
			arr[z][w]=0;
			visited[z][w]=0;
		}
	}
	// Read the co-ordinates from input file till lastline-1
	for(ctr=3;ctr<count;ctr++){
		getline(inFile,line);
		inFile >> i >> j;
		arr[i][j]=1;
	}
	inFile >> dir;  // Read the direction string
	inFile.close();
	int counter=0;
	for(string::iterator it=dir.begin(); it!=dir.end(); ++it){
		if(*it == 'E' && start<x-1){
			start=start+1;
		}
		else if(*it == 'W' && start>0){
			start=start-1;
		}
		else if(*it == 'N' && end<y-1){
			end=end+1;
		}
		else{
			if(*it== 'S' && end>0){
				end=end-1;
			}
		}
		if(arr[start][end]==1 && visited[start][end]!=1){
			visited[start][end]=1;
			counter++;
		}
	}
	cout << start << "\t" << end << endl;
	cout << counter << endl;
	// Free the arrays
	for(z=0;z<x;z++){
		delete [] arr[z];
		delete [] visited[z];
	}
	delete [] arr;
	delete [] visited;
}
