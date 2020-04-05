#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
string TimeArray[1000000];
string TeamArray[1000000];
string OpponentArray[1000000];
int HFFriendlyScore[1000000];
int HFOpponentScore[1000000];
int FTFriendlyScore[1000000];
int FTOpponentScore[1000000];
int HFOP,HFF,FTOP,FTF;
void GetNumber(string a,int index)
{
	int First=0;
	int Second=0;
	int Foundit=0;
	for(int i=0;i<a.size();i++)
	{
		if(int(a[i]) <= 57 && int(a[i]) >= 48)
		{
			int Digit = a[i] - '0'; 
			if(Foundit == 0)
			{
				First = First * 10 + Digit;
			}else{
				Second = Second * 10 + Digit;
			}
		}else if(int(a[i]) == 58)
		{
			Foundit=1;
		}
	}
	if(index == 5){
		HFF = First;
		HFOP = Second;	
		//cout<<HFF<<" "<<HFOP<<endl;
	}else{
		FTF = First;
		FTOP = Second;
		//cout<<FTF<<" "<<FTOP<<endl;
	}
}
int main()
{	
	fstream fs;
	fs.open ("DataSheet.txt", fstream::in);
	fstream Result;
	Result.open ("FormattedDataSheet.txt",fstream::out);
	string a="";
	
	int index = 1;
	int EntryN = 0;
	int LeagueID;
	cin>>LeagueID;
	while(true)
	{
		fs>>a;
		if( fs.eof() ) break;
		if(a != "" or a != "-")
		{
			//cout<<a<<" INDEX : "<<index<<endl;
			if(index == 1){
				TimeArray[EntryN] = a;
			}else if(index == 2){
				TeamArray[EntryN] = a;
			}else if(index == 3){
				
			}else if(index == 4){
				OpponentArray[EntryN] = a;
			}else if(index == 5){
				GetNumber(a,index); HFFriendlyScore[EntryN] = HFF; HFOpponentScore[EntryN] = HFOP;
			}else if(index == 6){
				GetNumber(a,index); FTFriendlyScore[EntryN] = FTF; FTOpponentScore[EntryN] = FTOP; EntryN++;
			}
			index++;
			if(index == 7)
			{
				index = 1;
			}
		}
	}
	for(int i=0;i<EntryN;i++){
		cout<<"A:"<<TimeArray[i]<<endl;
		cout<<"B:"<<TeamArray[i]<<endl;
		cout<<"C:"<<OpponentArray[i]<<endl;
		cout<<"D:"<<HFFriendlyScore[i]<<endl;
		cout<<"E:"<<HFOpponentScore[i]<<endl;
		cout<<"F:"<<FTFriendlyScore[i]<<endl;
		cout<<"G:"<<FTOpponentScore[i]<<endl;
	}
	
	Result<<LeagueID<<endl;
	for(int i=0;i<EntryN;i++){
		Result<<TimeArray[i]<<endl;
		Result<<TeamArray[i]<<endl;
		Result<<OpponentArray[i]<<endl;
		Result<<HFFriendlyScore[i]<<endl;
		Result<<HFOpponentScore[i]<<endl;
		Result<<FTFriendlyScore[i]<<endl;
		Result<<FTOpponentScore[i]<<endl;
	}
}
