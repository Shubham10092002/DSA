#include<bits/stdc++.h>
using namespace std;

void insertatbottom(stack<int> &st,int target){
	if(st.empty()){
		st.push(target);
		return;
	}

	int temp=st.top();
	st.pop();

	insertatbottom(st,target);
	st.push(temp);

}

void reverse(stack<int> &st){
	if(st.empty())
		return;

	int temp=st.top();
	st.pop();
	reverse(st);
	insertatbottom(st,temp);
}

void insertinsorted(stack<int>&st,int target){
if(st.empty()){


	st.push(target);
	return;

}
	
	if(st.top()>=target){
		st.push(target);
		return;
	}

	int temp=st.top();

	st.pop();
	insrtinsorted(st,target);
	st.push(temp);

}

vod sortstack(stack<int> &st){
	if(st.empty())
		return ;

	int temp=st.top();
	st.pop();
	sortstack(st);
	insertinsorted(st,temp);
	
}
int main(){
	//dynamic allocation
	//int* arr=new int[5];
	// free memory 
	//delete key world
	//delete[]


	//dynamically 2d array
	//int **arr=new int *[row];
	//for(int i=0; i<n; i++){
	// aar[i]=new int[colum];
//}
	//for(int i=0;i<row i++){

	//for(int j=0; j< colum ; j++){
	//cin >> arr[i][j];
//}

//}

	//release memory
	//for(int i=0; i<row; i++) delete [] arr[i];
	//deleting colum;
	//delete []arr;

	//macro #define pi 3.14

	//stack insert at bottom


	 stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);

  if(s.empty()) {
        cout << "stack is empty, cant insert at bottom" << endl;
        return 0;
  }

  int target = s.top();
  s.pop();
  insertatbottom(s, target);

  cout << "Printing" << endl;
  while(!s.empty()) {
          cout << s.top() << " ";
          s.pop();
  }

  cout << endl;
  return 0;


 
}