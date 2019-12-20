#ifndef UPDATABLE_H
#define UPDATABLE_H

#include <pthread.h>

/// This class is a base class that will start an update thread.
/// This thread will call the Update() method in any class that
/// inherits from it to do whatever that class needs done.
class Updatable {
public:
	Updatable();
	static void Lock() {
		pthread_mutex_lock(&mutex);
	}
	static void Unlock() {
		pthread_mutex_unlock(&mutex);
	}
	virtual void Update() = 0;
	
private:
	static const unsigned int MAX_UPDATABLES = 1000;
	static void* UpdateAll(void*);

	static bool delay;
	static Updatable* updatables[MAX_UPDATABLES];
	static unsigned int count;
	static pthread_t thread;
	static pthread_mutex_t mutex;
};
#endif
