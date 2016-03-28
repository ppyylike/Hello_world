#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;
void Insert_sort(vector<int>& v){
	int temp;size_t t,j;
	for(t=1;t!=v.size();t++){
		if(v[t]<v[t-1]){
		temp=v[t];
		j=t-1;
		while(v[j]>temp&&j!=0){
			v[j+1]=v[j];
			j--;
	}
		v[j+1]=temp;
		if(j==0){                              //需要考虑数组下标溢出 
			if(temp<v[0]){
			v[1]=v[0];
			v[0]=temp;
		}
		else v[1]=temp;
		}
	}
}
}
int main(){
	int x,i=0;
	vector<int> vi;
	while(i<50){
		x=rand()%500;
		vi.push_back(x);
		i++;
	}
	vector<int>::iterator t;
	for(t=vi.begin();t!=vi.end();t++){
		cout<<*t<<" ";
	}
	cout<<endl;
	Insert_sort(vi);
		for(t=vi.begin();t!=vi.end();t++){
		cout<<*t<<" ";
	}
	cout<<endl;
	return 0;
}
