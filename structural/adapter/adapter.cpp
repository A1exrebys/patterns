#include <iostream>
#include <string>

using namespace std;

typedef int Legacy;
typedef int Novice;

/* What we have */
class LegacyOperations
{
public:
	Legacy flash(string& str) const
	{
		cout << str << endl;
		return 0;
	}

	Legacy blink(string& str) const
	{
		cout << str << endl;
		return 0;
	}

	Legacy transfer(string& str) const
	{
		cout << str << endl;
		return 0;
	}
};

/* What we want */
class NoviceOperations
{
public:
	virtual Novice flash_led(int num) = 0;
	virtual Novice blink_led(int num) = 0;
	virtual Novice transfer_data(int sz) = 0;
};

class Adapter : public NoviceOperations, private LegacyOperations
{
public:
	Novice flash_led(int num)
	{
		string s = "flash led: " + to_string(num);
		Novice rv = flash(s);
		return rv;
	}

	Novice blink_led(int num)
	{
		string s = "blink led: " + to_string(num);
		Novice rv = blink(s);
		return rv;
	}

	Novice transfer_data(int sz)
	{
		string s = "transfer data with size: " + to_string(sz);
		Novice rv = transfer(s);
		return rv;
	}
	~Adapter() {};
};

int main() {
	NoviceOperations *novice = new Adapter;

	novice->flash_led(1);
	novice->blink_led(2);
	novice->transfer_data(100);

	return 0;
}