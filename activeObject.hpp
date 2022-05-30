#ifndef HEAD_ACTIVE_OBJECT
#define HEAD_ACTIVE_OBJECT

#include <list>

class ActiveObject
{
public:
	static std::list<ActiveObject*>& GetInstanceList();

	static void UpdateAll(float dt);

private:
	std::list<ActiveObject*>::iterator m_iter;

	bool m_inited;

public:
	ActiveObject();
	~ActiveObject();

	ActiveObject(const ActiveObject&) = delete;
	ActiveObject& operator=(const ActiveObject&) = delete;

	ActiveObject(ActiveObject&&) noexcept = default;
	ActiveObject& operator=(ActiveObject&&) noexcept = default;

	virtual void start() = 0;
	virtual void update(float dt) = 0;
};

#endif // !HEAD_ACTIVE_OBJECT
