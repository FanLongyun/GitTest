#include <string.h>
using namespace std;

class Request
{
public:
	Request(char *request) : information(request){}
	char *information;
};

class Chain
{
public:
	virtual bool getIdentity(char *identity) = 0;
	virtual void putRequest(char *info) = 0;
	virtual void solveRequest() = 0;
	virtual void setNextChain(Chain*) = 0;
	char *id;
	Chain* nextChain;
};

class TheChain : public Chain
{
public:
	char *id;
	TheChain(char* identity) : id(identity){}
	virtual bool getIdentity(char *identity)
	{
		return !strcmp(id, identity);
	}
	virtual void putRequest(char *info)
	{
		if (nextChain->getIdentity(info))
			nextChain->solveRequest();
		else
			nextChain->putRequest(info);
	}
	virtual void solveRequest()
	{
		cout<< *id <<" "<< "solved." << endl;
	}
	virtual void setNextChain(Chain* chain)
	{
		nextChain = chain;
	}
};

int main(int argc, char **argv)
{
	TheChain chain1("a");
	TheChain chain2("b");
	TheChain chain3("c");
	TheChain chain4("d");

	Request req("c");
	chain1.setNextChain(&chain2);
	chain2.setNextChain(&chain3);
	chain3.setNextChain(&chain4);
	chain1.putRequest(req.information);

	return 0;
}
