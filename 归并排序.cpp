#include<iostream>
#include<vector>
#include<cstdlib>
#define Elm int
using namespace std;
void Merge(vector<Elm> &A,vector<Elm> &B,size_t Lpos,size_t Rpos,size_t Rend){
	size_t i,Lend,Num,Temp;
	Lend=Rpos-1;
	Temp=Lpos;
	Num=Rend-Lpos+1;
	//maain loop
	while(Lpos<=Lend&&Rpos<=Rend){
		if(A[Lpos]<=A[Rpos])B[Temp++]=A[Lpos++];
		else B[Temp++]=A[Rpos++];
	}
	while(Lpos<=Lend)B[Temp++]=A[Lpos++];
	while(Rpos<=Rend)B[Temp++]=A[Rpos++];            //此处一次输入错误Rend误写为Rpos，检查了一个下午。。。 
	for(i=0;i<Num;i++,Rend--){
		A[Rend]=B[Rend];
	}
}
//递归实现合并 
void Msort(vector<Elm> &A,vector<Elm> &B,size_t left,size_t right){
	size_t center;
	if(left<right){
		center=(left+right)/2;
		Msort(A,B,left,center);
		Msort(A,B,center+1,right);
		Merge(A,B,left,center+1,right);
	}

}
//这个算法中并没有删除分配的内存 
void MergeSort(vector<Elm> &A){
	vector<Elm> B;
	B.resize(A.size());
	if(B.size()!=0){
		Msort(A,B,0,A.size()-1);
	}
	//B.clear();
} 

int main(){
	vector<Elm> ve;
	size_t t=0;
	while(t!=5000){
		ve.push_back(rand()%20000);
		t++;
	}
	t=0;
	while(t!=ve.size()){
		cout<<ve[t]<<" ";
		t++;
	}
	cout<<endl;
	MergeSort(ve);
	t=0;
	while(t!=ve.size()){
		cout<<ve[t]<<" ";
		t++;
	}
	return 0;
}
