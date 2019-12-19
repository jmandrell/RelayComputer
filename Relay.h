#ifndef RELAY_H
#define RELAY_H

#include <pthread.h>
#include <string>
#include "Io.h"

//#define DEBUG

class Relay {
public:
	Relay(const std::string& initName);
	void Update();
	void AttachActivate(Io* io) {
		activate.AttachInput(io);
	}
	Io* GetArmature() {
		return &armature;
	}
	Io* GetNo() {
		return &no;
	}
	Io* GetNc() {
		return &nc;
	}
	static void Lock() {
		pthread_mutex_lock(&mutex);
	}
	static void Unlock() {
		pthread_mutex_unlock(&mutex);
	}
	
private:
	static void* UpdateAll(void*);

	static Relay* relays[1000];
	static unsigned int relayCount;
	static pthread_t thread;
	static pthread_mutex_t mutex;
	
	const std::string name;
	Io activate;
	Io armature;
	Io nc;
	Io no;
};

#endif
