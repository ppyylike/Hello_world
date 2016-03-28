#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool por(char a,char b){
	if((a=='+'||a=='-')&&(b=='*'||b=='/'))return true;
	else return false;
}
int calc(int x,int y,char c){
	int tmp;
	switch(c){
		case '+':tmp=x+y;break;
		case '-':tmp=x-y;break;
		case '*':tmp=x*y;break;
		case '/':tmp=x/y;break;
	}
	return tmp;
}
void calc(string s,int &Nd){
	stack<int> Itstk;
	stack<char> Chstk;
	size_t t=0;
	while(t!=s.size()){
		if(s[t]>='0'&&s[t]<='9'){
			int temp=0;
			do{
				temp=temp*10+s[t]-48;
				t++;
			}while(s[t]>='0'&&s[t]<='9');
			Itstk.push(temp);
		}
		else{
			if(Chstk.empty()){
				Chstk.push(s[t]);
				t++;
			}
			else if(por(Chstk.top(),s[t])){
				Chstk.push(s[t]);
				t++;
			}
			else{
				int a=Itstk.top();Itstk.pop();
				int b=Itstk.top();Itstk.pop();
				char c=Chstk.top();Chstk.pop();
				Itstk.push(calc(b,a,c));
				Chstk.push(s[t]);
				t++;
			}
		}
	}
	while(!Chstk.empty()){
		int a=Itstk.top();cout<<Itstk.top()<<" ";
		Itstk.pop();
		int b=Itstk.top();cout<<Itstk.top()<<endl;
		Itstk.pop();
		char c=Chstk.top();cout<<Chstk.top()<<endl;
		Chstk.pop();
		Itstk.push(calc(b,a,c));cout<<Itstk.top()<<endl;
	}
	Nd=Itstk.top();
}
int main(){
	string str;
	cin>>str;
	int res=0;
	calc(str,res);
	cout<<res<<endl;
	return 0;
}
