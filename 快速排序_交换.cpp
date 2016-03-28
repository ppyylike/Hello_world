#include<iostream>
#include<vector>
#include<cstdlib>
#define Elm int
using namespace std;
void S_sort(vector<Elm>::iterator i,vector<Elm>::iterator j){
	vector<Elm>::iterator x=i,y=j,k;
	Elm temp=*x;
	while(x<y){
		while(*y>=temp&&y>x)y--;
		*x=*y;
		*y=temp;
		while(*x<=temp&&y>x)x++;
		*y=*x;
		*x=temp;
	}
	k=x;
	if(k-1>i)S_sort(i,k-1);
	if(k+1<j)S_sort(k+1,j);
}
int main(){
	vector<Elm> ve;
	size_t t=0;
	while(t!=4000){
		ve.push_back(rand()%20000);
		t++;
	}
	t=0;
	while(t!=ve.size()){
		cout<<ve[t]<<"¡¡";
		t++;
	}
	S_sort(ve.begin(),ve.end()-1);
	cout<<endl;
		t=0;
	while(t!=ve.size()){
		cout<<ve[t]<<"¡¡";
		t++;
	}
	return 0;
}
