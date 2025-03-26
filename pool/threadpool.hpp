#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <functional>
#include <condition_variable>
class pool
{
private:
    int thread_count;
    std::queue<std::function<void()>> works;
    std::vector<std::thread> thd;
    std::mutex mtx;
    std::condition_variable cv;
    bool runflag = true;
    template <typename F> 

public:
    pool(int n = 4) : thread_count(n){
        for (int i = 0; i < thread_count; i++){
            thd.emplace_back([this](){
                std::unique_lock<std::mutex> lock(mtx);
                while (runflag) {
                    cv.wait(lock, [this] { return !works.empty() || !runflag; });
                    if (!works.empty()) {
                        auto callback = works.front();
                        works.pop();
                        lock.unlock();
                        callback();
                        lock.lock();
                    }
                } });
        }
    }
    ~pool(){
        {
            std::unique_lock<std::mutex> lock(mtx);
            runflag = false;
        }
        cv.notify_all();
        for (auto &t : thd){
            if(t.joinable())
            t.join();
        }
    }
public:
    template <typename F, typename... Args>
    void enqueue(F &f,Args&&... args){
        auto task = std::bind(f, args...);
        std::unique_lock<std::mutex> lock(mtx);
        works.emplace(std::forward<F>(task));
        cv.notify_one();
    }
};