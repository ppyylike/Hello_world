#include<iostream>
#include<vector>
#include<cstdlib>
#define Elm int
using namespace std;
void Shell_sort(vector<Elm> &v){
	size_t a,b,incre;
	Elm temp;
	for(incre=v.size()/2;incre>0;incre/=2){
		for(a=incre;a<v.size();a++){
			temp=v[a];
			for(b=a;b>=incre;b-=incre){
				if(temp<v[b-incre])v[b]=v[b-incre];
				else break;
			}
			v[b]=temp;
		}
	}
}
int main(){
	vector<Elm> ve;
	size_t t=0;
	while(t<30){
		ve.push_back(rand()%1000);
		t++;
	}
	vector<Elm>::iterator i=ve.begin();
	while(i!=ve.end()){
		cout<<*i<<" ";
		i++;
	}
	Shell_sort(ve);
	cout<<endl;
	i=ve.begin();
	while(i!=ve.end()){
		cout<<*i<<" ";
		i++;
	}
	return 0;
}
