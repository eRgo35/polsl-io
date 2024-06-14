// przykład mierzenia czasu działania programu
// https://en.cppreference.com/w/cpp/chrono/high_resolution_clock/now


#include <chrono>


// record start time
        auto start = std::chrono::high_resolution_clock::now();
		
		
// do some work

// record end time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
		printf("Time measured: %.3f seconds.\n", diff.count() );
