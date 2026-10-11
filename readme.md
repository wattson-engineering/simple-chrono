Simplify time handling in embedded firmware.

Instead of waiting for delay, check whether it is time to execute a task. This method is efficient and avoids the need to use an RTOS for task management.

Most of the time, microcontrollers dont have synchronized datetime. It is just a counter of milliseconds started at the boot.

IF ((now - start) >= duration) DOSOMETHING

Quite simple but easier with simple_chrono API:
- Chrono specific type for variable
- Chrono reset function
- Chrono refresh function
- Chrono check function
- Chrono refreshAndCheck function
- Chrono refreshAndCheckAndReset(RCR) function

Example:
```
chrono.refresh()
if (chrono.check(duration)){
  //do task here
  chrono.reset();
}

OR

if (chrono.RCR(duration)){
  //do task here
}
```

---

## Plateforms
Counter of millisecond depends on the plateform:
- Arduino: based on millis()
- STM32 HAL: based on HAL_GetTick()
- RPI Pico SDK: based on get_absolute_time()
- TinyGo: based on time.Now()
- MicroZig: TODO
- MicroPython: based on time.ticks_ms()

## Overflow consideration
Millis counter overflow shouldn't be a problem. Because unsigned integer substraction result should be right with an overflow. But you should check it and use 64b integer if needed.

```
START = 250 = 0b11111010
NOW = 10 = 0b00001010
elapsed time = NOW - START

  00001010   (NOW)
+ 00000110   (2's Complement of START = 1's Complement +1)
-----------
  00010000   (16)


  5  (250 → 255)
+ 1  (overflow)
+ 10 (0 → 10)
= 16 ✅
```
