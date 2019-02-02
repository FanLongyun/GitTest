class Abstract
{
public:
	virtual void function1() = 0;
};

class RealObject : public Abstract
{
public:
	virtual void function1()
	{
		
	}
};

class Proxy
{
	Abstract *abs;
public:
	Proxy()
	{
		abs = new RealObject;
	}

	void proxyFunction1
	{
		proxyOperate();
		abs->function1();
	}

	void proxyOperate()
	{

	}
};

class client
{
public:
	Proxy pro;
	void run()
	{
		pro.proxyFunction1();
	}
};

