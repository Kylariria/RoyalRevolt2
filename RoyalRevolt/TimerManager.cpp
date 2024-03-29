#include "TimerManager.h"

TimerManager::TimerManager()
{
    clock = Clock();
    time = 0.0f;
    lastTime = 0.0f;
    lastFrameTime = 0.0f;
    elapsedTime = 0.0f;
    timeScale = 1.0f;
    deltaTime = 0.0f;
    framesCount = 0;
    maxFrameRate = 165;
    fps = 0;
}


void TimerManager::UpdateTimers()
{
    for (const auto& _pair : allValues)
    {
        _pair.second->Update(deltaTime);
    }

    GarbageValues();
}


void TimerManager::Update()
{
    lastTime = time;
    time = static_cast<float>(clock.getElapsedTime().asMilliseconds());
    elapsedTime = time - lastTime;
    deltaTime = elapsedTime * timeScale;
    framesCount++;

    UpdateTimers();
    if (Render() && renderCallback)
    {
        renderCallback();
    }
}

void TimerManager::Pause()
{
    for (auto& _pair : allValues)
    {
        _pair.second->Pause();
    }
}

void TimerManager::Play()
{
    for (auto& _pair : allValues)
    {
        _pair.second->Start();
    }
}
