#include<iostream>
#include <cmath>
#include<iomanip>
#include <cstdlib>

//int gcd(int x,int y);
using namespace std;

int gcd(int x,int y)
{
if(x!=0&&y!=0)
return gcd((x>=y)?x%y:x,(x<y)?y%x:y);
else
return(x!=0)?x:y;
} 

int main()
{
	double option[14][5]={{9900,665,755,16.5,17.5},//�i����[][0],call�R��[][1],call���[][2],put�R��[][3],put���[][4] 
					{10000,585,670,21.5,22},
					{10100,510,520,28.5,30},
					{10200,424,428,40.5,41},
					{10300,339,343,55,56},
					{10400,263,265,77,78},
					{10500,190,194,107,108},
					{10600,132,135,147,150},
					{10700,87,89,201,205},
					{10800,54,55,266,271},
					{10900,32.5,33,345,349},
					{11000,19,20,432,436},
					{11100,12.5,13,520,535},
					{11200,2.1,8.1,580,665}};
					
	double taiex[3];
	double future[3];
	double r=0.01844, t=1/12;
	
	cout<<"Please input the bid price of TAIEX : ";
	cin>>taiex[1];
	cout<<"Please input the ask price of TAIEX : ";
	cin>>taiex[2];
	cout<<"Please input the bid price of Future : ";
	cin>>future[1];
	cout<<"Please input the ask price of Future : ";
	cin>>future[2];
	cout<<endl;
	
	//Theorem2-call
	for(int i=0;i<=12;i++){
		for(int j=i+1;j<=13;j++){
			if(option[j][1]-option[i][2]>2){
			//cout<<"There would be an arbitrage: "<<"Buying call option with strike price: "<<option[i][0]<<" and selling call option with strike price: "<<option[i+1][0]<<endl;
			//cout<<"Paying "<<option[i][1]<<", Receiving "<<option[i+1][1]<<", and the payoff: "<<option[i+1][1]-option[i][1]-2<<endl;
			cout<<"Arbitrage with Theorem2-call:"<<endl
				<<"Buy one call option "<<option[i][0]<<" cost "<<option[i][2]
				<<", and sell one call option "<<option[j][0]<<endl
				<<"(for 1~2 is strike price is low to high, c: call price; X: strike price)"<<endl
				<<"At maturity"
				<<endl
				<<"if St<=X1, Profit = c2-c1-2"<<option[j][1]-option[i][2]-2<<endl
				<<"if X1<St<X2, Profit = c2-c1+St-X1-2"<<option[j][1]-option[i][2]<<" -St -"<<option[i][0]-2<<endl
				<<"if St>=X2, Profit = c2-c1+X2-X1-2"<<option[j][1]-option[i][2]+option[j][0]-option[i][0]-2<<endl<<endl;
			}
		}
	}
	
	//Theorem2-put
	for(int i=0;i<=12;i++){
		for(int j=i+1;j<=13;j++){
			if(option[i][3]-option[j][4]>2){
			//cout<<"There would be an arbitrage: "<<"Buying call option with strike price: "<<option[i][0]<<" and selling call option with strike price: "<<option[i+1][0]<<endl;
			//cout<<"Paying "<<option[i][1]<<", Receiving "<<option[i+1][1]<<", and the payoff: "<<option[i+1][1]-option[i][1]-2<<endl;
			cout<<"Arbitrage with Theorem2-put:"<<endl
				<<"Sell one put option "<<option[i][0]<<" get "<<option[i][3]
				<<", and buying one put option "<<option[j][0]<<endl
				<<"(for 1~2 is strike price is low to high, p: put price; X: strike price)"<<endl
				<<"At maturity"
				<<endl
				<<"if St<=X1, Profit = p1-p2+X2-X1-2"<<option[i][3]-option[j][4]+option[j][0]-option[i][0]-2<<endl
				<<"if X1<St<X2, Profit = p1-p2+X2-St-2"<<option[i][3]-option[j][4]+option[j][0]<<" -St"<<-2<<endl
				<<"if St>=X2, Profit = p1-p2-2"<<option[i][3]-option[j][4]-2<<endl<<endl;
			}
		}
	}
	
	//Theorem3-call
	for(int i=0;i<=13;i++){
		if(option[i][1]-taiex[2]>2)
			cout<<"Arbitrage with Theorem3-call:"<<endl
				<<"Buy the taiex and selling the call with strike price "<<option[i][0]
				<<"If St>X, we get the strike price ;If St<X, we get the stock price at the maturity"
				<<"At maturity"
				<<endl
				<<"if the St>X, Profit = c-S0+X-2 "<<option[i][1]-taiex[2]+option[i][0]-2<<endl
				<<"if the St<X, Profit = c-S0+St-2"<<option[i][1]-taiex[2]<<"+St-2"<<endl<<endl;
	}
	
	//Theorem3-put
	for(int i=0;i<=13;i++){
		if(option[i][3]-option[i][0]*exp(-r*t)>1)
			cout<<"Arbitrage with Theorem3-put: "<<endl
				<<"Sell the put with the strike price"<<option[i][0]<<" and save  the present value of strike price"
				<<"If St>X, we get the strike price ;If St<X,we get the spot price at the maturity"
				<<"At maturity"
				<<endl
				<<"if the St>X, Profit = p-PV(X)+X-1"<<option[i][3]-option[i][0]*exp(-r*t)+option[i][0]-1<<endl
				<<"if the St<X, Profit = p-PV(X)+St-1"<<option[i][3]-option[i][0]*exp(-r*t)<<"+St-1"<<endl<<endl;
	}
	
	//Theorem4 (call)
	for(int i=0;i<=13;i++){
		int value=taiex[1]-option[i][0]*exp(-r*t);
		int test;
		if(value>0)
			test=value;
		else
			test=0;
		if(test-option[i][2]>2){
			cout<<"Arbitrage with Theorem4 (call):"<<endl
				<<"Buy call costs "<<option[i][2]<<", Saving costs PV("<<option[i][0]<<") = option[i][0]*exp(-r*t)"
				<<"Sell the taiex(Spot,S) gets "<<taiex[1]<<endl
				<<"At maturity"
				<<endl
				<<"if St>X, Profit = S0-c-PV(X)-2"<<taiex[1]-option[i][2]-option[i][0]*exp(-r*t)-2<<endl
				<<"if St<X, Profit = S0-c-PV(X)+X-St-2"<<taiex[1]-option[i][2]-option[i][0]*exp(-r*t)+option[i][0]-2<<"-St"<<endl<<endl;
		}
	}
	
	//Theorem6 (put)
	for(int i=0;i<=13;i++){
		int value=option[i][0]*exp(-r*t)-taiex[2];
		int test;
		if(value>0)
			test=value;
		else
			test=0;
		if(test-option[i][4]>2){
			cout<<"Arbitrage with Theorem6 (put):"<<endl
				<<"Buy put costs "<<option[i][4]<<", Borrowing gets PV("<<option[i][0]<<") = option[i][0]*exp(-r*t)"
				<<"Buy the taiex costs "<<taiex[2]<<endl
				<<"At maturity"
				<<endl
				<<"if St>X, Profit = PV(X)-S0-p+St-X-2"<<option[i][0]*exp(-r*t)-taiex[2]-option[i][4]-option[i][0]-2<<"-St"<<endl
				<<"if St<X, Profit = PV(X)-S0-p-2"<<option[i][0]*exp(-r*t)-taiex[2]-option[i][4]-2<<endl<<endl;
		}
	}
	//Theorem8
	for(int i=0;i<=11;i++){
		for(int j=i+1;j<=12;j++){
			for(int k=j+1;k<=13;k++){
				double omega=(option[k][0]-option[j][0])/(option[k][0]-option[i][0]);
				omega=omega*1000000;
				//cout<<"~ omega "<<omega<<endl;
				int m=1000000;
				int g=gcd(omega,m);
				//cout<<"g: "<<g<<endl;
				omega=omega/g;
				//cout<<"omega: "<<omega<<endl;
				m=m/g;
				//cout<<"m: "<<m<<endl;//cout<<"m: "<<m<<", g:"<<g<<endl;
				if(m*option[j][1]-omega*option[i][2]-(m-omega)*option[k][2]>3){
					cout<<"Arbitrage with Theorem8-call:"<<endl
						<<"Sell "<<m<<" units of strike price "<<option[j][0]<<" get "<<m*option[j][1]
						<<"Buy "<<omega<<" units of strike price "<<option[i][0]<<" cost "<<omega*option[i][2]
						<<"buy "<<(m-omega)<<" units of strike price "<<option[k][2]<<" cost "<<(m-omega)*option[k][2]
						<<"w: "<<omega<<" ;m: "<<m<<endl<<"(for 1~3: strike price low to high)"
						<<"At maturity"
						<<endl
						<<"if St<X1, Profit = m*c2-omega*c1-(m-omega)c3-3"<<endl
						<<"if X1<St<X2, Profit = m*c2-omega*c1-(m-omega)c3+m(St-X1)-3"<<endl
						<<"if X2<St<X3, Profit = m*c2-omega*c1-(m-omega)c3+w(St-X1)-m*(X2-St)-3"<<endl
						<<"if St>X3, Profit = m*c2-omega*c1-(m-omega)c3-3"<<endl<<endl;
				}
				if(m*option[j][3]-omega*option[i][4]-(m-omega)*option[k][4]>3){
					cout<<"Arbitrage with Theorem8-put:"<<endl
						<<"Sell "<<m<<" units of strike price "<<option[j][0]<<" get "<<m*option[j][3]
						<<"Buy "<<omega<<" units of strike price "<<option[i][0]<<" cost "<<omega*option[i][4]
						<<"buy "<<(m-omega)<<" units of strike price "<<option[k][0]<<" cost "<<(m-omega)*option[k][2]
						<<"(for 1~3: strike price low to high)"<<endl
						<<"At maturity"
						<<endl
						<<"if St<X1, Profit = m*p2-omega*p1-(m-omega)p3-3"<<endl
						<<"if X1<St<X2, Profit = m*p2-omega*p1-(m-omega)p3+w(St-X1)-3"<<endl
						<<"if X2<St<X3, Profit = m*p2-omega*p1-(m-omega)p3+(m-omega)(X3-St)-3"<<endl
						<<"if St>X3, Profit = m*p2-omega*p1-(m-omega)p3-3"<<endl<<endl;
				}
			}
		}
	}
	
	//Theorem9-2
	for(int i=0;i<=13;i++){
		if((option[i][1]-option[i][4])-(future[2]-option[i][0])*exp(-r*t)>3){
			cout<<"Arbitrage with Theorem9-2-1:"<<endl
				<<"Selling call gets:"<<option[i][1]<<endl
				<<"Buy put costs:"<<option[i][4]<<endl
				<<"Buy futures costs:"<<future[2]<<endl
				<<"Profit:"<<(option[i][1]-option[i][4])-(future[2]-option[i][0])*exp(-r*t)-3<<endl<<endl;
		}
		
	for(int i=0;i<=13;i++){
		if((future[1]-option[i][0])*exp(-r*t)-(option[i][2]-option[i][3])>3){
			cout<<"Arbitrage with Theorem9-2-2:"<<endl
				<<"Buy call costs:"<<option[i][2]<<endl
				<<"Sell put gets:"<<option[i][3]<<endl
				<<"Sell futures gets:"<<future[1]<<endl
				<<"Profit:"<<(future[1]-option[i][0])*exp(-r*t)-(option[i][2]-option[i][3])-3<<endl<<endl;
		}	
	}
}
	return 0;
} 
