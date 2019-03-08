#include <list>
#include <iterator>

class component
{
public:
	component()
	{}
	virtual void process() = 0;
	~component()
	{}
};

class composite : public component
{
public:
	void addComposite(composite* comp)
	{
		Composites.push_back(comp);
	}

	void removeComposite(composite* comp)
	{
		Composites.remove(comp);
	}

	virtual void process()
	{
		if (!Composites.empty())
		{
			std::list<composite*>::iterator iter;
			for (iter = Composites.begin(); iter != Composites.end(); iter++)
			{
				(*iter)->process();
			}
		}
	}

private:
	std::list<composite*> Composites;
};

class leaf : public component
{
public:
	virtual void process()
	{
		// process leaf node
	}
};

void startProcess(component& comp)
{
	comp.process();
}

int main(int argc, char **argv)
{
	composite root;
	composite branch1;
	composite branch2;
	leaf leaf1;
	root.addComposite(&branch1);
	root.addComposite(&branch2);
	root.addComposite(&leaf1);
	startProcess(root);

	return 0;
}