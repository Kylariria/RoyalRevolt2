#include "Timer.h"
#include "TimerManager.h"

Timer::Timer(const string& _id, const function<void()>& _callback, const Time& _time,
    const bool _startRunning, const bool _isLoop) : IManagable(_id)
{
    Register();

    callback = _callback;
    currentDuration = 0.0f;
    duration = static_cast<float>(_time.asMilliseconds());
    isRunning = _startRunning;
    isLoop = _isLoop;
}


void Timer::Register()
{
    TimerManager::GetInstance().Add(id, this);
}


void Timer::Update(const float _deltaTime)
{
    if (!isRunning) return;

    currentDuration += _deltaTime;
    if (currentDuration >= duration)
    {
        Reset();
        if (callback)
        {
            callback();
        }

        if (!isLoop)
        {
            Stop();
        }
    }
}

void Timer::Start()
{
    isRunning = true;
}

void Timer::Pause()
{
    if (isRunning = true)
    {
        isRunning = false;
    }

    isRunning = true;
}

void Timer::Reset()
{
    currentDuration = 0.0f;
}

void Timer::Stop()
{
    TimerManager::GetInstance().Remove(id);
}