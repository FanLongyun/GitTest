class Application1
{
public:
	void exchangeDataWith2(void *data)
	{

	}
	void exchangeDataWith3(void *data)
	{

	}
};

class Application2
{
public:
	void exchangeDataWith1(void *data)
	{

	}
	void exchangeDataWith3(void *data)
	{

	}

};

class Application3
{
public:
	void exchangeDataWith2(void *data)
	{

	}
	void exchangeDataWith3(void *data)
	{

	}
};

class Applications
{
public:
	virtual void exchangeDataWithMediator(void *data) = 0;
};

class Application1 : public Applications
{
public:
	virtual void exchangeDataWithMediator(void *data)
	{

	}
};

class Application2 : public Applications
{
public:
	virtual void exchangeDataWithMediator(void *data)
	{

	}
};

class Application3 : public Applications
{
public:
	virtual void exchangeDataWithMediator(void *data)
	{

	}
};

class Mediator
{
public:
	void exchangeDataWithApp(void *data)
	{

	}
};

class Client
{
	Applications *app;
public:
	Client(int index)
	{
		switch (index)
		{
		case 0:
			app = new Application1;
			break;
		case 1:
			app = new Application2;
			break;
		case 2:
			app = new Application3;
			break;
		default:
			break;
		}
	}
	void run()
	{
		app->exchangeDataWithMediator(data);
	}
	char *data;
};