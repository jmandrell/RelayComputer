#include <unistd.h>
#include <stdlib.h>

#include "Updatable.h"

unsigned int Updatable::count = 0;
Updatable* Updatable::updatables[Updatable::MAX_UPDATABLES];
pthread_t Updatable::thread;
pthread_mutex_t Updatable::mutex;
bool Updatable::delay = false;

static bool started = false;

Updatable::Updatable(bool show) {
	if (show) {
		updatables[count++] = this;
		if (count >= MAX_UPDATABLES) {
			exit(1);
		}
		// don't run the thread for a bit
		delay = true;
		if (!started) {
			pthread_mutex_init(&mutex, 0);
			pthread_create(&thread, 0, Updatable::UpdateAll, 0);
			started = true;
		}
	}
}

void* Updatable::UpdateAll(void*) {
	for (;;) {
		usleep(500);
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


