#include <unistd.h>
#include "Updatable.h"

unsigned int Updatable::count = 0;
Updatable* Updatable::updatables[1000];
pthread_t Updatable::thread;
pthread_mutex_t Updatable::mutex;
bool Updatable::delay = false;

static bool started = false;

Updatable::Updatable() {
	updatables[count++] = this;
	// don't run the thread for a bit
	delay = true;
	if (!started) {
		pthread_mutex_init(&mutex, 0);
		pthread_create(&thread, 0, Updatable::UpdateAll, 0);
		started = true;
	}
}

void* Updatable::UpdateAll(void*) {
	for (;;) {
		usleep(10000);
		while (delay) {
			delay = false;
			usleep(50000);
		}
		pthread_mutex_lock(&mutex);
		for (unsigned int i = 0; i < count; ++i) {
			updatables[i]->Update();
		}
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}


