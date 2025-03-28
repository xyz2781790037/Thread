#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <tuple>
class pool
{
private:
    int thread_count;
    std::queue<std::function<void()>> works;
    std::vector<std::thread> thd;
    std::mutex mtx;
    std::condition_variable cv;
    bool runflag = true;

public:
    pool(int n = 4) : thread_count(n){
        for (int i = 0; i < thread_count; i++){
            thd.emplace_back([this]() {
                while (true) {
                    std::function<void()> callback;{
                        std::unique_lock<std::mutex> lock(mtx);
                        cv.wait(lock, [this]
                                { return !works.empty() || !runflag; });
                        if (!runflag && works.empty())
                        {
                            return;
                        }
                        if (!works.empty())
                        {
                            callback = std::move(works.front());
                            works.pop();
                        }
                    }if (callback){
                       callback();
                    }
                } });
        }
    }
    ~pool(){{
            std::unique_lock<std::mutex> lock(mtx);
            runflag = false;
        }
        cv.notify_all();
        for (auto &t : thd){
            if (t.joinable())
                t.join();
        }
    }
public:
    template <typename F, typename... Args>
    void enqueue(F &&f, Args &&...args){
        auto task = [f = std::forward<F>(f), args = std::make_tuple(std::forward<Args>(args)...)]() mutable
        {
            std::apply([&f](auto &&...args) { std::invoke(f, std::forward<decltype(args)>(args)...); 
            }, args);
        };
        {
            std::unique_lock<std::mutex> lock(mtx);
            works.emplace(std::move(task));
        }
        cv.notify_one();
    }
};