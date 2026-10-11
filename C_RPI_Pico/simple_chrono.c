/*
 * simple_chrono.c
 *
 */

#include "simple_chrono.h"

void ChronoReset(Chrono* c) {
	c->initTime = to_ms_since_boot(get_absolute_time());
	c->elapsedTime = 0;
}

// Refreshes elapsed time and Returns true if the time is elapsed.
bool ChronoRefreshAndCheck(Chrono* c, uint32_t duration){
	ChronoRefresh(c);
	return ChronoCheck(c,duration);
}

// Refreshes elapsed time
void ChronoRefresh(Chrono* c){
	c->elapsedTime = to_ms_since_boot(get_absolute_time()) - c->initTime;
}


// Returns true if the time is elapsed.
bool ChronoCheck(Chrono* c, uint32_t duration) {
	return c->elapsedTime >= duration;
}

// Returns duration
uint32_t ChronoGetElapsedTime(Chrono* c) {
	return c->elapsedTime;
}

// Returns true if the time is elapsed.
// Performs Refresh, Check, Reset in one function
bool ChronoRCR(Chrono* c, uint32_t duration){
	if (ChronoRefreshAndCheck(c,duration)) {
        ChronoReset(c);
        return true;
    }
    return false;
}
