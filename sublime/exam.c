/*#include<stdio.h>
#include<stdlib.h>

int stack[100],n;
int top=-1;
void push(){
    
    int x;
    scanf("%d",&x);
    if(top==n){
        printf("overflow");
        return ;

    }
    else{

    
    top++;
    stack[top]=x;
    
    }

}

int main(){
    printf("Enter the size  of stack");
    scanf("%d",&n);
    printf("enter the element in stack");
    for(int i=0; i< n; i++){
    push();

    }

printf("entered element in the stack");
    for (int j=top; j<=0; j--){
        printf("%d",stack[j]);
    }
    return 0;

*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int x[3];
        for(int i=0; i<3; i++){
            cin >> x[i];
        }

        sort(x,x+3);

        if(x[2]+x[1]>=10)
            cout <<"YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}