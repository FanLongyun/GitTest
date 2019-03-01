// Memento.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Memento
{
public:
	Memento()
	{

	}
	Memento(const void *data, int size)
	{
		memcpy(m_data, data, size);
	}

	void changeData(void *data, int size)
	{
		memcpy(m_data, data, size);
	}

private:
	void *m_data;
};

class NoteBook
{
public:
	NoteBook()
	{

	}
	NoteBook(Memento& mem)
	{
		Memento temp(mem);
		m_mem = &temp;
	}

	Memento saveMemento(const Memento& mem)
	{
		m_mem = new Memento(mem);
		return *m_mem;
	}

	Memento restoreMemento()
	{
		if (m_mem != nullptr)
			return *m_mem;
		else
		{
			Memento empty(NULL, 0);
			return empty;
		}
	}
	
private:
	Memento *m_mem;
};

int main()
{
	// 生成一个信息库
	Memento meme;

	// 生成备忘录
	NoteBook notebook;

	// 存储信息
	notebook.saveMemento(meme);

	// meme信息修改
	meme.changeData(NULL, 0);

	// 恢复
	meme = notebook.restoreMemento();

    return 0;
}

