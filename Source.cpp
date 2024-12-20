#include <iostream>
#include <string>

using namespace std;


class BankAccount {
	long long int id;
	string name;
	double balance;

public:

	BankAccount(const long long int& Bid, const string& Bname, const double& Bbalance) : id(Bid), name(Bname), balance(Bbalance) {}

	void deposit(const double& deposit) {
		cout << "Deposit: " << deposit << endl;
		balance += deposit;
	}

	void withdraw(const double& withdraw) {
		cout << "Withdraw: " << withdraw << endl;
		balance -= withdraw;
	}

	double get_balance() {
		return balance;
	}


};

class SavingsAccount : public BankAccount {
	int percent;

public:
	SavingsAccount(const long long int& Sid, const string& Sname, const double& Sbalance, const int& Spercent) : BankAccount(Sid, Sname, Sbalance), percent(Spercent) {}

	void addpercent() {
		cout << "Percent added: " << BankAccount::get_balance() * percent / 100 << endl;
		BankAccount::deposit(BankAccount::get_balance() * percent/100);
		
	}
};

int main() {

	SavingsAccount myacc(131, "Kirill", 1000, 15);

	cout << "Balance:  " << myacc.get_balance() << endl;

	myacc.deposit(5000);

	cout << "Balance:  " << myacc.get_balance() << endl;

	myacc.withdraw(250.2);

	cout << "Balance:  " << myacc.get_balance() << endl;

	for (int i = 0; i < 10; i++) {
		myacc.addpercent();
		cout << endl;
	}
	
	cout << "Balance:  " << myacc.get_balance() << endl;


}