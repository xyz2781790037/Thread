#include <iostream>
#include <vector>
using namespace std;
typedef struct SearchConfig
{
    std::string root_path;               // 要搜索的根目录
    std::string file_type;               // 要搜索的文件类型，如 ".txt"、".cpp" 等
    int max_concurrency;                 // 最大并发数
    int max_depth;                       // 最大搜索深度
    bool skip_hidden;                    // 是否跳过隐藏文件或目录
    std::vector<std::string> skip_paths; // 要跳过的目录或文件的路径
}sc;
class look_file{
public:
    sc path;
};
int main()
{
    return 0;
}