#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
	vector<string> roman={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	vector<int> numeros={1,4,5,9,10,40,50,90,100,400,500,900,1000};



int findR(string A){
	for(int i=0;i<roman.size();i++){
		if(A==roman[i]){
			return i;
		}
	}
	return -1;
}


int RTD(string input){
	//int size=input.size()-1;
	int number=0;
	int i=0;
	while(i<input.size()){
		string temp="";
		temp=temp+input[i]+input[i+1];
		int pos=findR(temp);
		if(pos==-1){
			temp="";
			temp=temp+input[i];
			pos=findR(temp);
			i++;
		}
		else
			i+=2;
		number+=numeros[pos];
	}
	return number;
};



string DTR(int input){
	string answer="";
	int i=12;
	while(input!=0){
		if(input>=numeros[i]){
			input-=numeros[i];
			answer=answer+roman[i];	
		}
		else{
			i--;
		}
	};
	return answer;
};


int main(){
	string input;
	while(cin>>input){
		if(isdigit(input[0]))
			cout<<DTR(stoi(input))<<endl;
		else
			cout<<RTD(input)<<endl;
	}
}
