#include "Inverter.h"

Inverter::Inverter(const std::string &initName) : name(initName), relay(name + " relay") {
}
