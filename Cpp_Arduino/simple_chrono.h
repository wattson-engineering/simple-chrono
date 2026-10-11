/*
 * simple_chrono.h
 *
 */

#ifndef _CHRONO_H
#define _CHRONO_H

#include <Arduino.h>

typedef struct Chrono {
	uint32_t initTime;
	uint32_t elapsedTime;
} Chrono;

void ChronoReset(Chrono* c);

// Refreshes elapsed time and Returns true if the time is elapsed.
bool ChronoRefreshAndCheck(Chrono* c, uint32_t duration);

// Refreshes elapsed time
void ChronoRefresh(Chrono* c);

// Returns true if the time is elapsed.
bool ChronoCheck(Chrono* c, uint32_t duration);

// Returns duration
uint32_t ChronoGetElapsedTime(Chrono* c);

#endif