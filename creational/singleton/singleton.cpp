#include <iostream>
#include <string>

using namespace std;

class Singleton {
private:
	Singleton()
	{
	}

public:
	static Singleton& getSingleton()
	{
		static Singleton inst;

		return inst;
	}

	Singleton(Singleton const&) = delete;
	void operator=(Singleton const&) = delete;
}

int main() {
	Singleton& singl = Singleton::getSingleton();

	return 0;
}