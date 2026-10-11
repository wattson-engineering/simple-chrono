import time

class Chrono:
    def __init__(self):
        self._init_time = 0
        self._elapsed_time = 0
        self.reset()

    def reset(self):
        self._init_time = time.ticks_ms()
        self._elapsed_time = 0

    def refresh(self):
        """Refreshes elapsed time"""
        self._elapsed_time = time.ticks_diff(time.ticks_ms(), self._init_time)

    def check(self, duration_ms):
        """Returns true if the time is elapsed."""
        return self._elapsed_time >= duration_ms

    def refresh_and_check(self, duration_ms):
        """Refreshes elapsed time and Returns true if the time is elapsed."""
        self.refresh()
        return self.check(duration_ms)

    def get_elapsed_time(self):
        return self._elapsed_time