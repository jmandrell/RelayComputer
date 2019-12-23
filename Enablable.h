#ifndef ENABLABLE_H
#define ENABLABLE_H

#include "Io.h"

class Enablable {
public:
	virtual void AttachEnable(Io* io) = 0;
};

#endif
