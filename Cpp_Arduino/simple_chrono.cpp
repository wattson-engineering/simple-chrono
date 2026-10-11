/*
 * simple_chrono.cpp
 *
 */

#include "simple_chrono.h"

void ChronoReset(Chrono* c) {
	t->initTime = millis();
	t->elapsedTime = 0;
}

// Refreshes elapsed time and Returns true if the time is elapsed.
bool ChronoRefreshAndCheck(Chrono* c, uint32_t duration){
	ChronoRefresh(c);
	return ChronoCheck(c,duration);
}

// Refreshes elapsed time
void ChronoRefresh(Chrono* t){
	c->elapsedTime = millis() - c->initTime;
}


// Returns true if the time is elapsed.
bool ChronoCheck(Chrono* c, uint32_t duration) {
	return c->elapsedTime >= duration;
}

// Returns duration
uint32_t ChronoGetElapsedTime(Chrono* c) {
	return c->elapsedTime;
}
