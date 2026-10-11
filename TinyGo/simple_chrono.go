package simple_chrono

import "time"

type Chrono struct {
	initTime    time.Time
	elapsedTime time.Duration
}

func (c *Chrono) Reset() {
	c.initTime = time.Now()
	c.elapsedTime = 0
}

// Refreshes elapsed time and Returns true if the time is elapsed.
func (c *Chrono) RefreshAndCheck(duration time.Duration) bool {
	c.Refresh()
	return c.Check(duration)
}

// Refreshes elapsed time
func (c *Chrono) Refresh() {
	c.elapsedTime = time.Since(c.initTime)
}

// Returns true if the time is elapsed.
func (c *Chrono) Check(duration time.Duration) bool {
	return c.elapsedTime >= duration
}

func (c *Chrono) GetElapsedTime() time.Duration {
	return c.elapsedTime
}