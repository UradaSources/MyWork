#include "activeObject.hpp"

ActiveObject::ActiveObject() : m_inited(false)
{
	auto list = ActiveObject::GetInstanceList();

	list.push_back(this);
	m_iter = --list.end();
}
ActiveObject::~ActiveObject()
{
	auto list = ActiveObject::GetInstanceList();
	list.erase(m_iter);
}

std::list<ActiveObject*>& ActiveObject::GetInstanceList()
{
	static std::list<ActiveObject*> _instanceList;
	return _instanceList;
}

void ActiveObject::UpdateAll(float dt)
{
	auto list = ActiveObject::GetInstanceList();
	for (auto i : list)
	{
		ActiveObject& gm = *i;

		if (!gm.m_inited)
			gm.start();
		gm.update(dt);
	}
}
