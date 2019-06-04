
#include <iostream>
#include <string>

using namespace std;

class Investment
{
public: 
	Investment(string name, int price)
	{
		m_name = name;
		m_price = price;
	}

	virtual ~Investment()
	{}

	string name() const
	{
		return m_name;
	}

	virtual bool fungible() const = 0;
	
	
	virtual string description() const = 0;


	int purchasePrice() const
	{
		return m_price;
	}


private:
	string m_name;
	int m_price;

};

class Painting : public Investment
{
public:

	Painting(string name, int price) : Investment(name, price)
	{}

	virtual ~Painting()
	{
		cout << "Destroying " << name() << ", a " << description() << endl;
	}

	virtual bool fungible() const
	{
		return false;
	}

	virtual string description() const
	{
		return ("painting");
	}
};

class Stock : public Investment			//INITIALIZER LIST???
{
public:
	Stock(string name, int price, string stock):Investment(name, price), m_stock(stock)
	{
		/*m_name = name;
		m_price = price;
		m_stock = stock;*/
	}

	virtual ~Stock()
	{
		cout << "Destroying " << name() << ", a stock holding" << endl;
	}

	virtual bool fungible() const
	{
		return true;
	}

	string stock() const
	{
		return m_stock;
	}

	virtual string description() const
	{
		return ("stock trading as " + stock());
	}



private:
	
	string m_stock;
};

class House : public Investment
{
public:
	House(string name, int price) : Investment(name, price)
	{}

	virtual ~House()
	{
		cout << "Destroying the " << description() << " " << name() << endl;
	}

	virtual bool fungible() const
	{
		return false;
	}

	virtual string description() const
	{
		return ("house");
	}
};

