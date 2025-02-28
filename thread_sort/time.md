## chrono库函数
chrono是一个测量时间的函数，`#include<chrono>` 是 C++ 标准库中的头文件，提供了用于处理时间和时间间隔的功能。chrono（来自希腊语“时间”）主要用于高精度计时、时间单位转换和时间点计算。

### 主要功能：

1. **时间点（time_point）**：表示某个具体的时间，如 `std::chrono::system_clock::now()` 获取当前系统时间。

2. **时长（duration）**：表示时间间隔，如 `std::chrono::seconds(10)` 表示 10 秒。

3. 时钟（clock）

   ：

   - `system_clock`：系统时钟，表示当前时间，可用于获取时间戳。
   - `steady_clock`：单调递增时钟，适用于测量时间间隔，保证不会倒退。
   - `high_resolution_clock`：高精度时钟，通常是 `steady_clock` 的别名。

```c++
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::high_resolution_clock::now(); // 记录开始时间

    std::this_thread::sleep_for(std::chrono::seconds(2)); // 让线程休眠 2 秒

    auto end = std::chrono::high_resolution_clock::now(); // 记录结束时间

    std::chrono::duration<double> elapsed = end - start; // 计算时间间隔
    std::cout << "代码执行时间: " << elapsed.count() << " 秒" << std::endl;

    return 0;
}
```