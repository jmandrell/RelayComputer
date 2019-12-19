#include <unistd.h>
#include <iostream>
#include "Relay.h"

unsigned int Relay::relayCount = 0;
Relay* Relay::relays[1000];
pthread_t Relay::thread;
pthread_mutex_t Relay::mutex;

static bool started = false;

Relay::Relay(const std::string& initName) : name(initName) {
	relays[relayCount++] = this;
	if (!started) {
		pthread_mutex_init(&mutex, 0);
		pthread_create(&thread, 0, Relay::UpdateAll, 0);
		started = true;
	}
}

void* Relay::UpdateAll(void*) {
	for (;;) {
		usleep(10000);
		pthread_mutex_lock(&mutex);
		for (unsigned int i = 0; i < relayCount; ++i) {
			relays[i]->Update();
		}
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}


void Relay::Update() {
	if (activate.GetOutput()) {
#ifdef DEBUG
		std::cerr << "NO "
				  << armature.GetOutput() << " "
				  << no.GetOutput() << std::endl;
#endif
		// NO is activated
		bool state = armature.GetOutput(false) || no.GetOutput(false);
		armature.Force(state);
		no.Force(state);
		nc.Force(false);
	} else {
#ifdef DEBUG
		std::cerr << "NC "
				  << armature.GetOutput() << " "
				  << nc.GetOutput() << std::endl;
#endif
		// NC is activated
		bool state = armature.GetOutput(false) || nc.GetOutput(false);
		armature.Force(state);
		nc.Force(state);
		no.Force(false);
	}
}
