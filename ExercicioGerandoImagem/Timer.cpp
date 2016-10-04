#include "Timer.h"
#include <ctime>

class Timer {
public:
	Timer() { reset(); }
	void start() { begin = clock(); }
	void finish() { end = clock(); }
	void reset() {
		begin = 0;
		end = 0;
	}
	double getElapsedTimeMs() {
		double e = ((double)(end - begin)) / CLOCKS_PER_SEC;
		return e * 1000;
	}
	double calcWaitingTime(int fps, double elapsedTime) {
		return 1000 / fps - elapsedTime;
	}
private:
	clock_t begin, end;
};
