#include<iostream>
#include<cmath>
#include<vector>
#include<cstdlib>
using namespace std;
void Bubble_sort(vector<int>& v){
	size_t i,j;
	for(i=0;i!=v.size();i++){
		int temp=v[i];
		for(j=i;j!=v.size();j++)
		if(v[j]<v[i]){
			temp=v[i];
			v[i]=v[j];
			v[j]=temp;
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
	Bubble_sort(vi);
		for(t=vi.begin();t!=vi.end();t++){
		cout<<*t<<" ";
	}
	return 0;
}
