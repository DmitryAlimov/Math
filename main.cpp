#include <iostream>
#include <experimental/random>
#include "Eigen/Dense"
using namespace std;

class arr{
public:
    arr(int Nx, int Ny){
        data_ptr = new Eigen::MatrixXd(Nx, Ny);
        for (int i=0; i < Nx; i++) {
            for (int j = 0; j < Ny; j++) {
                (*data_ptr)(i, j) = 0;
            }
        }
    }
    Eigen::MatrixXd get() {
        return *data_ptr;
    }

    void set(Eigen::MatrixXd &inp_arr) {
        if ((*data_ptr).cols() == inp_arr.cols() && (*data_ptr).rows() == inp_arr.rows()) {
            (*data_ptr) = inp_arr;
        } else {
            cout << endl << "ERROR arrays have different dimensions!" << endl;
        }
    }

    void set(arr inp_arr) {
        if ((*data_ptr).cols() == (inp_arr.get()).cols() && (*data_ptr).rows() == (inp_arr.get()).rows()) {
            (*data_ptr) = inp_arr.get();
        } else {
            cout << endl << "ERROR arrays have different dimensions!" << endl;
        }
    }

    void set(int i, int j, double val){
        (*data_ptr)(i, j) = val;
    }

    int nx(){
        return (*data_ptr).cols();
    }

    int ny(){
        return (*data_ptr).rows();
    }

    void transpose(){
        if ((*data_ptr).cols() == (*data_ptr).rows()){
            Eigen::MatrixXd tmp = (*data_ptr);
            for (int i=0; i<(*data_ptr).cols(); i++){
                for (int j=0; j<(*data_ptr).cols(); j++) {
                    (*data_ptr)(i, j) = tmp(j, i);
                }
            }
        } else {
            cout << endl << "ERROR array is not quadratic" << endl;
        }
    }

    void print(){
        cout << endl;
        for (int i=0; i<(*data_ptr).cols(); i++) {
            string tmp = "";
            for (int j = 0; j < (*data_ptr).rows(); j++) {
                tmp.append(to_string((*data_ptr)(i, j)));
                tmp.append("   ");
            }
            cout << tmp << endl;
        }
    }

    arr operator+( arr &other ) {
        arr tmp1 = other;
        Eigen::MatrixXd tmp2 = other.get() + (*data_ptr);
        tmp1.set(tmp2);
        return tmp1;
    }

    arr operator-( arr &other ) {
        arr tmp1 = other;
        Eigen::MatrixXd tmp2 = other.get() - (*data_ptr);
        tmp1.set(tmp2);
        return tmp1;
    }

    arr operator*( arr &other ) {
        Eigen::MatrixXd tmp_arr((*data_ptr).cols(), (other.get()).rows());
        for (int i=0; i < (*data_ptr).cols(); i++){
            for (int j=0; j < (other.get()).rows(); j++){
                double tmp = 0;
                for (int k=0; k < (*data_ptr).rows(); k++){
                    tmp += (*data_ptr)(i, k)*(other.get())(k, j);
                }
                tmp_arr(i, j) = tmp;
            }
        }
        arr otp((*data_ptr).cols(), (other.get()).rows());
        otp.set(tmp_arr);
        return otp;
    }
private:
    Eigen::MatrixXd *data_ptr;
};


int main(){
    /*arr a(2, 2);
    a.set(1, 0 , -3);
    a.transpose();
    a.print();*/

    arr a(2, 2);
    a.set(0, 0, 5);
    arr aa(2, 2);
    aa.set(0, 0, 8);
    aa = a*aa;
    a.print();
    aa.print();


    return 0;
}

