#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum PCType {
    One,
	Two
};

class PC
{
public:
	virtual void Run() const = 0;
	virtual void Stop() const  = 0;

	virtual ~PC() {};
};

class Laptop : public PC
{
public:
	virtual void Run() const override
	{
		cout << "Run..." << endl;
	}

	virtual void Stop() const override
	{
		cout << "...Stop" << endl;
	}

	virtual ~Laptop() {};
};

class Mini : public PC
{
public:
	virtual void Run() const override
	{
		cout << "Run..." << endl;
	}

	virtual void Stop() const override
	{
		cout << "...Stop" << endl;
	}

	virtual ~Mini() {};
};

class PCFactory
{
public:
	static unique_ptr<PC> NewPC(PCType type)
	{
		if (type == One) {
			return make_unique<Laptop>();
		} else if (type == Two) {
			return make_unique<Mini>();
		}
	}
};

int main() {
	unique_ptr<PC> pc = PCFactory::NewPC(PCType::One);
	pc->Run();

	return 0;
}