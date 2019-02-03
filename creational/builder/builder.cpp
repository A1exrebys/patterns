#include <iostream>
#include <string>

using namespace std;

class Payload {
public:
	void SetType(const string& t)
	{
		_type = t;
	}

	void SetHWType(const string& t)
	{
		_hwtype = t;
	}

	void SetCRC(int c)
	{
		_crc = c;
	}

	void Print()
	{
		cout << "type = " << _type << " crc = " << _crc << endl;
	}
private:
	string _type;
	string _hwtype;
	int _crc;
};

class PayloadBuilder {
public:
	virtual void BuildType() = 0;
	virtual void BuildHWType() = 0;
	virtual void BuildCRC() = 0;

	void CreatePayload()
	{
		_payload = make_unique<Payload>();
	}

	Payload* GetPayload()
	{
		return _payload.release();
	}

protected:
	unique_ptr<Payload> _payload;
};

class NewPyload : public PayloadBuilder
{
public:
	~NewPyload() {};

	void BuildType()
	{
		_payload->SetType("Ethernet");
	}

	void BuildHWType()
	{
		_payload->SetHWType("Cable");
	}

	void BuildCRC()
	{
		_payload->SetCRC(0xFFFF);
	}

	void Print()
	{
		_payload->Print();
	}
};

class Build
{
public:
	void BuildPayload(PayloadBuilder *pb)
	{
		_pb = pb;
		_pb->CreatePayload();
		_pb->BuildType();
		_pb->BuildHWType();
		_pb->BuildCRC();
	}

private:
	PayloadBuilder *_pb;
};

int main() {
	Build bd;
	NewPyload newpd;

	bd.BuildPayload(&newpd);

	newpd.Print();

	return 0;
}