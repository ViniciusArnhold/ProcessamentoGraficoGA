/* ___                                                        _            ___            __ _                       ___   _
  / _ \_ __ ___   ___ ___  ___ ___  __ _ _ __ ___   ___ _ __ | |_ ___     / _ \_ __ __ _ / _(_) ___ ___             / _ \ /_\
 / /_)/ '__/ _ \ / __/ _ \/ __/ __|/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \   / /_\/ '__/ _` | |_| |/ __/ _ \   _____   / /_\///_\\
/ ___/| | | (_) | (_|  __/\__ \__ \ (_| | | | | | |  __/ | | | || (_) | / /_\\| | | (_| |  _| | (_| (_) | |_____| / /_\\/  _  \
\/    |_|  \___/ \___\___||___/___/\__,_|_| |_| |_|\___|_| |_|\__\___/  \____/|_|  \__,_|_| |_|\___\___/          \____/\_/ \_/
							Unisinos 2016 - Vinicius Pegorini Arnhold e Reni Steffenon
*/
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
