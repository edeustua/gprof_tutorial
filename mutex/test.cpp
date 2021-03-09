#include <thread>
#include <mutex>
#include <iostream>


void safe_increment(std::mutex & g_i_mutex, int & g_i)
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;

    std::cout << "g_i: " << g_i << "; in thread #"
              << std::this_thread::get_id() << '\n';

    // g_i_mutex is automatically released when lock
    // goes out of scope
}

int main()
{
    int g_i = 0;
    std::mutex g_i_mutex;  // protects g_i

    std::cout << "g_i: " << g_i << "; in main()\n";

    std::thread t1(safe_increment, std::ref(g_i_mutex), std::ref(g_i));
    std::thread t2(safe_increment, std::ref(g_i_mutex), std::ref(g_i));

    t1.join();
    t2.join();

    std::cout << "g_i: " << g_i << "; in main()\n";
}
