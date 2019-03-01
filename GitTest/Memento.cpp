// Memento.cpp : �������̨Ӧ�ó������ڵ㡣
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
	// ����һ����Ϣ��
	Memento meme;

	// ���ɱ���¼
	NoteBook notebook;

	// �洢��Ϣ
	notebook.saveMemento(meme);

	// meme��Ϣ�޸�
	meme.changeData(NULL, 0);

	// �ָ�
	meme = notebook.restoreMemento();

    return 0;
}

