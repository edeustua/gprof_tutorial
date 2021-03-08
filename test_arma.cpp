#include <iostream>
#include <vector>
#include <armadillo>
#include <chrono>
#include <cstdlib>

#include <unistd.h>

int main(int argc, char *argv[]) {

    std::size_t mat_size;

    if (argc == 2) {
        mat_size = atoi(argv[1]);
    } else {
        mat_size = 100;
    }
    std::cout << "Matrix size: " << mat_size << std::endl;

    arma::mat A(mat_size, mat_size, arma::fill::randu);
    arma::mat B(mat_size, mat_size, arma::fill::randu);

    auto start = std::chrono::high_resolution_clock::now();
    arma::mat C = A * B;
    auto end = std::chrono::high_resolution_clock::now();

    if (mat_size == 2) {
        std::cout << C << std::endl;
    }

    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if (milliseconds.count() > 10000) {
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        std::cout << "Took: " << seconds.count() << "s" << std::endl;
    } else {
        std::cout << "Took: " << milliseconds.count() << "ms" << std::endl;
    }



    return 0;
}
