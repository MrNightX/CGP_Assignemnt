
#ifndef _FRAMETIMER_ // Include Guards

#define _FRAMETIMER_
#include <windows.h> // Window Library
#define WIN32_LEAN_AND_MEAN // Compile Important Window Library Only

class FrameTimer
{
private:
	LARGE_INTEGER frequencyTime;
	LARGE_INTEGER currentTime;
	LARGE_INTEGER previousTime;
	int requestedFPS;
	float ticksPerFrame;
	float deltaTime;

public:
	FrameTimer();			// Null Constructor
	FrameTimer(int);		// Full Constructor
	~FrameTimer();			// Destructor
	void init(int);			// Initialize FrameTimer
	int framesToUpdate();	// Calculate numberOfFrames to update
};

#endif _FRAMETIMER_
