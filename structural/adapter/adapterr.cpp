#include <iostream>
#include <string>

using namespace std;

class Headphonse
{
public:
	virtual ~Headphonse() = default;
	virtual void listen(void) const = 0;
};

class Jack : public Headphonse
{
public:
	void listen(void) const override
	{
		cout << "listen" << endl;
	}
};

class WHeadphonse
{
public:
	virtual ~WHeadphonse() = default;
	virtual void blisten(void) const = 0;
};

class Bluetooth : public WHeadphonse
{
public:
	void blisten(void) const override
	{
		cout << "blisten" << endl;
	}
};

class Adapter : public Headphonse
{
private:
	WHeadphonse &heads;
public:
	Adapter(WHeadphonse &inst) : heads(inst)
	{
	}
	void listen() const override
	{
		heads.blisten();
	}

};

int main() {
	Jack jack;
	Bluetooth ble;
	Adapter *adapter = new Adapter(ble);

	adapter->listen();

	return 0;
}