#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double dataset[], int array_size, double result_statistics[]){
    double sum_of_data = 0.0;
    double sum_of_square_data = 0.0;
    double product_of_data = 1.0;
    double sum_of_reciprocal_data = 0.0;
    
    double maximum_data = dataset[0];
    double minimum_data = dataset[0];
    
    for(int i = 0; i < array_size; i++){
        double piece_of_data = dataset[i];
        sum_of_data += piece_of_data;
        sum_of_square_data += piece_of_data * piece_of_data;
        product_of_data *= piece_of_data;
        sum_of_reciprocal_data += 1.0 / piece_of_data;
        if(piece_of_data > maximum_data){
            maximum_data = piece_of_data;
        }
        if(piece_of_data < minimum_data){
            minimum_data = piece_of_data;
        }
    }
    double arithmetic_mean = sum_of_data / array_size;
    double variance = (sum_of_square_data / array_size) - (arithmetic_mean * arithmetic_mean);
    double standard_deviation = sqrt(variance);
    double geometric_mean = pow(product_of_data, 1.0 / array_size);
    double harmonic_mean = array_size / sum_of_reciprocal_data;
    
    result_statistics[0] = arithmetic_mean;
    result_statistics[1] = standard_deviation;
    result_statistics[2] = geometric_mean;
    result_statistics[3] = harmonic_mean;
    result_statistics[4] = maximum_data;
    result_statistics[5] = minimum_data;
}