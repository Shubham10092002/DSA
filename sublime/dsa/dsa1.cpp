#include<iostream>
using namespace std;

int main(){

	int p[3][3];
	
	for(int i=0; i <3; i++){

	for(int j=0;j<3; j++){

		cin >> p[i][j];
	}

}
int i=2, j=3;
p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+p[i][j];


	return 0;
}