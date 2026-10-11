/*
 * simple_chrono.c
 *
 */

#include "simple_chrono.h"

void ChronoReset(Chrono* c) {
	c->initTime = HAL_GetTick();
	c->elapsedTime = 0;
}

// Refreshes elapsed time and Returns true if the time is elapsed.
bool ChronoRefreshAndCheck(Chrono* c, uint32_t duration){
	ChronoRefresh(c);
	return ChronoCheck(c,duration);
}

// Refreshes elapsed time
void ChronoRefresh(Chrono* c){
	c->elapsedTime = HAL_GetTick() - c->initTime;
}


// Returns true if the time is elapsed.
bool ChronoCheck(Chrono* c, uint32_t duration) {
	return c->elapsedTime >= duration;
}

// Returns duration
uint32_t ChronoGetElapsedTime(Timer* c) {
	return c->elapsedTime;
}
