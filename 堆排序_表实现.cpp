#include<iostream>
#include<cstdlib>
#include<vector>
#define Elm int
using namespace std;
void sw(size_t x,size_t y,vector<Elm> &v){
	Elm temp=v[x];
	v[x]=v[y];
	v[y]=temp;
}
/*          这部分考未虑下标为0的情形 
void T_f(size_t t,vector<Elm> &v){
	 if(2*t+1<=v.size()){
		if(v[2*t]>=v[2*t+1]){
			if(v[2*t]>v[t]){
				sw(t,2*t,v);
				if(2*t<=v.size()/2)T_f(2*t,v);
			}
		}
		else{
			if(v[2*t+1]>v[t]){
				sw(t,2*t+1,v);
				if(2*t+1<=v.size()/2)T_f(2*t+1,v);
			}
		}
	}
	else{
		if(v[t]<v[2*t]){
			sw(t,2*t,v);
		}
	}
}
void Hp(vector<Elm> &v){
	size_t t;
	for(t=v.size()/2;t!=0;t--)T_f(t,v);
}
void Hsort(vector<Elm> &v,vector<Elm> &vl){
	size_t t=0;
	while(v.size()!=0){
		vl.push_back(v[0]);
		v[0]=v.back();
		v.pop_back();
		T_f(0,v);
	}
}
*/
void T_f(size_t t,vector<Elm> &v){
	 if(2*t+1<=v.size()-1){
		if(v[2*t]>=v[2*t+1]){
			if(v[2*t]>v[t]){
				sw(t,2*t,v);
				if(2*t<=(v.size()-1)/2)T_f(2*t,v);                       //递归实现元素的交换，使得最大元素排在堆顶 
			}
		}
		else{
			if(v[2*t+1]>v[t]){
				sw(t,2*t+1,v);
				if(2*t+1<=(v.size()-1)/2)T_f(2*t+1,v);
			}
		}
	}
	else{
		if(v[t]<v[2*t]){
			sw(t,2*t,v);
		}
	}
}
void Hp(vector<Elm> &v){
	size_t t;
	for(t=(v.size()-1)/2;t!=0;t--)T_f(t,v);
}
void Hsort(vector<Elm> &v,vector<Elm> &vl){
	size_t t=1;
	while(v.size()!=1){
		vl.push_back(v[1]);
		v[1]=v.back();
		v.pop_back();
		T_f(1,v);
	}
}
int main(){
	vector<Elm> ve,vl;size_t t=1;
	ve.push_back(0);
	while(t!=5001){
		ve.push_back(rand()%10000);
		t++;
	}
	Hp(ve);
	Hsort(ve,vl);
	t=0;
	while(t!=vl.size()){
		cout<<vl[t]<<" ";
		t++;
	}
	return 0;
} 
