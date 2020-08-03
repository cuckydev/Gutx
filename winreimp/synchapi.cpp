#include <synchapi.h>
#include <string.h>
#include <vector>
#include <algorithm>

class MUTEX : public _HANDLE
{
	private:
		char *name = nullptr;
		
	public:
		MUTEX(LPCSTR _name)
		{
			if (_name != nullptr)
				name = new char[strlen(_name) + 1];
		}
		
		~MUTEX() override
		{
			delete[] name;
		}
		
		const char *GetName() const { return name; }
};

std::vector<MUTEX*> mutexes;

HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName)
{
	if (lpName == nullptr)
		return nullptr;
	for (auto &i : mutexes)
		if (i->GetName() != nullptr && !strcmp(i->GetName(), lpName))
			return i;
	return nullptr;
}

HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
	for (auto &i : mutexes)
		if (i->GetName() != nullptr && !strcmp(i->GetName(), lpName))
			return nullptr;
	MUTEX *mutex = new MUTEX(lpName);
	mutexes.push_back(mutex);
	return mutex;
}

BOOL WINAPI ReleaseMutex(HANDLE hMutex)
{
	mutexes.erase(std::remove(mutexes.begin(), mutexes.end(), hMutex), mutexes.end());
	delete hMutex;
	return TRUE;
}
