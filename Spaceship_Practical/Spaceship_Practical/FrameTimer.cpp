#include "FrameTimer.h"

// FrameTimer Null Constructor
FrameTimer::FrameTimer()
{
	// 60 FPS in default
	init(60);
}

// FrameTimer Full Constructor
FrameTimer::FrameTimer(int fps)
{
	// Customized FPS
	init(fps);
}

// Initialize FrameTimer
void FrameTimer::init(int fps)
{
	// 1. Get frequencyTime, currentTime and previousTime from CPU
	QueryPerformanceFrequency(&frequencyTime);
	QueryPerformanceCounter(&currentTime);
	QueryPerformanceCounter(&previousTime);

	// 2. Get requestedFPS from outside
	requestedFPS = fps;

	// 3. Get ticksPerFrame for consistency
	ticksPerFrame = ((float)frequencyTime.QuadPart / requestedFPS);

}

// Calculate numberOfFrames to update
int FrameTimer::framesToUpdate()
{
	// 1. Define number of frames to update
	int frameCount;

	// 2. Get currentTime from CPU
	QueryPerformanceCounter(&currentTime);

	// 3. Calculate deltaTime (difference of currentTime & previousTime)
	deltaTime = (float)currentTime.QuadPart - (float)previousTime.QuadPart;

	// 4. Calculate frameCount
	frameCount = (int)(deltaTime / ticksPerFrame);

	// 5. Update previousTime only if frameCount is not zero, for consistency
	if (frameCount != 0)
	{
		QueryPerformanceCounter(&previousTime);
	}

	// 6. Return frameCount to update
	return frameCount;

}

// FrameTimer Destructor
FrameTimer :: ~FrameTimer()
{

}