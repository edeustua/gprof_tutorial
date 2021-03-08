#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include <unistd.h>

class Matrix {
    private:
        double *data;
    public:
        std::vector<std::size_t> shape;

        Matrix(std::vector<std::size_t> shape_) : shape(shape_) {
            data = new double[size()];
        }

        int size() {
            int cnt = 1;
            for (auto i : shape) {
                cnt *= i;
            }
            return cnt;
        }

        const double & operator()(std::size_t x, std::size_t y) const {
            return data[x*shape[0] + y];
        }

        double & operator()(std::size_t x, std::size_t y) {
            return data[x*shape[0] + y];
        }


        friend std::ostream & operator<<(std::ostream & out, const Matrix & mat);

        ~Matrix() {
            delete [] data;
        }
};

std::ostream & operator<<(std::ostream & out, const Matrix & mat) {
    for (std::size_t i=0; i<mat.shape[0]; i++) {
        for (std::size_t j=0; j<mat.shape[1]; j++) {
            out << "  " << mat(i, j);
        }
        out << std::endl;
    }
    return out;
}


void fill_mat(Matrix & A) {
    for (int i=0; i<A.shape[0]; i++) {
        for (int j=0; j<A.shape[1]; j++) {
            A(i, j) = i*A.shape[0] + j;
        }
    }
}


Matrix matmul(Matrix & A, Matrix & B) {
    if (A.shape[1] != B.shape[0]) {
        throw "Matrix dimensions don't match";
    }

    Matrix C({A.shape[0], B.shape[1]});

    for (std::size_t i=0; i<A.shape[0]; i++) {
        for (std::size_t j=0; j<B.shape[1]; j++) {
            for (std::size_t k=0; k<B.shape[0]; k++) {
                C(i, j) += A(i, k) * B(k, j);
            }
        }
    }

    return C;
}


int main(int argc, char *argv[]) {

    std::size_t mat_size;

    if (argc == 2) {
        mat_size = atoi(argv[1]);
    } else {
        mat_size = 100;
    }
    std::cout << "Matrix size: " << mat_size << std::endl;

    Matrix A({mat_size, mat_size});
    Matrix B({mat_size, mat_size});

    fill_mat(A);
    fill_mat(B);


    auto start = std::chrono::high_resolution_clock::now();
    Matrix C = matmul(A, B);
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
