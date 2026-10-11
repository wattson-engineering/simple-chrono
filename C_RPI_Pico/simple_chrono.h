/*
 * simple_chrono.h
 *
 */

#ifndef INC_CHRONO_H_
#define INC_CHRONO_H_

#include <stdbool.h>
#include <stdint.h>
#include "pico/stdlib.h"


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

// Returns true if the time is elapsed.
// Performs Refresh, Check, Reset in one function
bool ChronoRCR(Chrono* c, uint32_t duration);

#endif /* INC_CHRONO_H_ */
