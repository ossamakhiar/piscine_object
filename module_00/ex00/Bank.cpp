#include "Bank.hpp"

size_t Bank::account_id = 0;

Bank::Bank() : liquidity(0)
{

}

Bank::Bank(int _liquidity) : liquidity(_liquidity)
{

}

Bank::~Bank()
{
	std::cout << "deconstruction...\n";
	for (std::map<int, Account*>::const_iterator it = accounts_db.begin(); it != accounts_db.end(); ++it)
		delete it->second;
	this->accounts_db.clear();
}

Bank::Bank(const Bank& other)
{
    *this = other;
}

Bank&	Bank::operator=(const Bank& rhs)
{
	if (this == &rhs)
		return (*this);

	for (std::map<int, Account*>::const_iterator it = accounts_db.begin(); it != accounts_db.end(); ++it)
		delete it->second;
	this->accounts_db.clear();

	this->liquidity = rhs.liquidity;
	for (std::map<int, Account*>::const_iterator it = rhs.accounts_db.begin(); it != rhs.accounts_db.end(); ++it)
		this->accounts_db.insert(std::pair<int, Account*>(it->first, new Account(*(it->second))));
	return (*this);
}


// * GETTERS & SETTERS
const int&	Bank::get_liquidity() const
{
	return (this->liquidity);
}

void	Bank::set_liquidity(int liquidity)
{
	this->liquidity = liquidity;
}


// * public Behaviors

int	Bank::create_account(int initial_amount)
{
	int fee;

	if (initial_amount < 0)
		throw MyRuntimeError("Cannot create an account with negative amount");

	fee = 0.05 * initial_amount;
	this->liquidity += fee;
	initial_amount -= fee;
	this->accounts_db.insert(std::pair<int, Account*>(account_id, new Account(account_id, initial_amount)));

	account_id++;
	return (account_id - 1);
}

void	Bank::close_account(int id)
{
	std::map<int, Account *>::iterator	it;

	if ((it = accounts_db.find(id)) == accounts_db.end())
		throw MyRuntimeError("This given account id doesn't exist");
	this->accounts_db.erase(it);
}

void	Bank::deposit_money(int id, int amount)
{
	int									fee;
	std::map<int, Account *>::iterator	it;

	if ((it = accounts_db.find(id)) == accounts_db.end())
		throw MyRuntimeError("This given account id doesn't exist");

	if (amount <= 0)
		throw MyRuntimeError("invalid amount!, your amount should be a positive value");
	fee = amount * 0.05;
	this->liquidity += fee;
	it->second->value += (amount - fee);
}

void	Bank::withdraw_money(int id, int amount)
{
	std::map<int, Account *>::iterator	it;

	if ((it = accounts_db.find(id)) == accounts_db.end())
		throw MyRuntimeError("This given account id doesn't exist");

	if (amount > it->second->value)
		throw MyRuntimeError("rejeceted!, insufficient funds for withdraw");
	it->second->value -= amount;
}

void	Bank::give_loan(int id, int loan_amount)
{
	std::map<int, Account *>::iterator	it;

	if ((it = accounts_db.find(id)) == accounts_db.end())
		throw MyRuntimeError("This given account id doesn't exist");

	if (liquidity < loan_amount)
		throw MyRuntimeError("Insufficient funds for the loan.");
	it->second->value += loan_amount;
	liquidity -= loan_amount;
}



const Account& Bank::operator[](size_t id)
{
	std::map<int, Account *>::iterator	it;

	if ((it = accounts_db.find(id)) == accounts_db.end())
		throw MyRuntimeError("This given account id doesn't exist");
	return *(it->second);
}

// *-- printing function
std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
	p_os << "h";
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;
	for (std::map<int, Account*>::const_iterator it = p_bank.accounts_db.begin(); it != p_bank.accounts_db.end(); ++it)
		p_os << *(it->second) << std::endl;
	return (p_os);
}
