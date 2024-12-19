#include <iostream>
#include <vector>
#include <Eigen/Dense> // Requires Eigen library
using namespace std;
using namespace Eigen;

void pca(const MatrixXd& data, int components) {
    // Step 1: Calculate the mean of each column
    RowVectorXd mean = data.colwise().mean();
    MatrixXd centered = data.rowwise() - mean;

    // Step 2: Calculate covariance matrix
    MatrixXd cov = (centered.transpose() * centered) / (data.rows() - 1);

    // Step 3: Perform Eigen decomposition
    SelfAdjointEigenSolver<MatrixXd> solver(cov);
    MatrixXd eigenVectors = solver.eigenvectors().rightCols(components);
    cout << "Principal Components:\n" << eigenVectors << endl;

    // Step 4: Project data onto the principal components
    MatrixXd transformed = centered * eigenVectors;
    cout << "Transformed Data:\n" << transformed << endl;
}

int main() {
    MatrixXd data(5, 3);
    data << 2.5, 2.4, 0.8,
            0.5, 0.7, 0.9,
            2.2, 2.9, 0.7,
            1.9, 2.2, 1.0,
            3.1, 3.0, 1.1;

    int components = 2;
    pca(data, components);
    return 0;
}

