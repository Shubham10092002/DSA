
//map//
/*#include<bits/stdc++.h>
using namespace std;
int main(){
	
	/*map<string,int> m;

	int n;
	cin >> n;

	for(int i=0; i<n; i++){

		
		string key;

		cin >> key;
		
		
		m[key]++;
	}
	m.erase("abc");
 cout << m.size() << endl;

	map<string,int>:: iterator it=m.begin();

	for(it=m.begin(); it!=m.end(); it++){

		cout << (*it).first <<" " <<(*it).second <<endl;
	}





	return 0;


 for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }*/

  /*      #include <iostream>
using namespace std;

void print1(int n)
{

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j < i; j++)
        {

            cout << j << " ";
        }
        for (int j = 1; j < 2 * n + 1 - 2 * i; j++)
        {
            cout << i << " ";
        }

        for (int j = i; j >= 0; j--)
        {
            cout << j << " ";
        }

        cout << endl;
        
    }
}

void print2(int n)
{
    int num=n-1;

    for (int i = 1; i <= n; i++)
    {
       // int num=n--;

        for (int j = 0; j <=n-i; j++)
        {

            cout << j << " ";
        }

         for (int j = 0; j < 2*i-1; j++)
        {
            cout << num  << " ";
        }

         for (int j = num; j >= 0; j--)
        {
            cout << j << " ";
        }

        
        num--;
        cout << endl;
    }

}

int main()
{
    int n;
    cin >> n;

    print1(n);
    print2(n);

    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

   string convert(string s, int numRows){
    

    int n=numRows;
    int i=0; 
    int j=0;
    int k=0;
    string ans="";
    int c[100][100]={0};

    while(k < s.size()){

          if(i==0){
            for(i=0 ; i < n; i++){
                c[i][j]=s[k];
                k++;

                
             }
         }

        else{
            
           
            c[i][j]=s[k];
            k++;

            }

             i--;
            j++;

        }


        for(int x=0; x<n; x++){
            for(int y=0; y<100; y++){
                if(c[x][y] > 64 && c[x][y] < 91){

                	char ch=c[x][y];
                    ans+=ch;
                }
            }
        }

        cout << ans.size() << " " << endl;

        return ans;
    }

int main(){

string s="PAYPALISHIRING";
int n=s.size();

int numRows=4;

cout << n << " " << endl;

  cout << convert(s,numRows) << " " << endl;

	return 0;
}

//PAHNAPLSIIGYIR