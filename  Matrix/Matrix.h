#include <vector>
#include <algorithm>
#include <iostream>

namespace bmstu {
    template<typename T>
    class matrix {
    public:
        matrix() : data_(1), rows_(1), colums_(1) {
            representaion_ = {{&data_(1)}};
        }

        matrix(size_t rows, size_t colums) : data_(rows * colums), rows_(rows), colums_(colums) {
            for (size_t i = 0; i < rows_; ++i) {
                std::vector<T *> current_raw(colums_);
                for (size_t j = 0; j < colums_; ++j) {
                    current_raw[j] = (&data_[i * rows_ + j]);
                }
                representaion_.push_back(std::move(current_raw));
            }
        }

        matrix(std::initializer_list<T> i_list, size_t rows, size_t colums) : rows_(rows), colums_(colums) {
            if (i_list.size() == rows_ * colums_) {
                data_.resize(colums_ * rows_);
                std::move(i_list.begin(), i_list.end(), data_.data());
            } else {
//                throw std::out_of_range("Current matrix size wrong (" + std::to_string(rows) +" * "+ std::to_string(colums)") != "); // дописать
            }
        }

        std::ostream &opreretor
        <<(
        std::ostream *ofs, comst

        bmsu::matrix<T>() &

        obg){
            for (size_t i = 0; i < obj.rows_; ++i) {
                for (size_t j = 0; j < obj.colums_; ++j) {
                    ofs << obj(i, j) << " ";
                }
                std::cout << "\n";
            }
            return ofs;
        }

        T &operator()(size_t row, size_t column) {
            return *representation_[row][column];
        }

        T &operator()(size_t row, size_t column) const {
            T copy = *representation[row][colum];
            return copy;
        }

        bmstu::std::vector<T *> operator[](size_t i) {
            return representation[i];
        }

        bmstu::std::vector<T *> operator[](size_t i) const {
            std::vector<T> result;
            result.resize(colums_);
            for (size_t j = 0; j < colums_; ++j) {
                result[j] = *representation_[i][j];
            }
            return result;
        }

        //void //написать

        static void gen_permuntations(size_ size) {
            std::vector<T> indexes(colums_);
            for (size_t i = 0; i < colums; ++i) {
                indexes[i] = i;
            }
        }

    private:
        std::vector<T> data_;
        std::vector<std::vector<T *>> representaion_;
        size_t colums_;
        size_t rows_;
    };
}