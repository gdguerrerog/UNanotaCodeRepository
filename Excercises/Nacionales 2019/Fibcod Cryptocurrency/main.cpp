#include <iostream>

using namespace std;

#define MODULO 524288

/*

matrix indexes are:
0 1
2 3

*/
long long * matrix2x2Mult(long long * m1, long long * m2){
    long long * exit = new long long[4];
    exit[0] = (m1[0]*m2[0] + m1[1]*m2[2]) % MODULO;
    exit[1] = (m1[0]*m2[1] + m1[1]*m2[3]) % MODULO;
    exit[2] = (m1[2]*m2[0] + m1[3]*m2[2]) % MODULO;
    exit[3] = (m1[2]*m2[1] + m1[3]*m2[3]) % MODULO;

    return exit;
}

void copyMatrix(long long * origin, long long * destiny){
    destiny[0] = origin[0];
    destiny[1] = origin[1];
    destiny[2] = origin[2];
    destiny[3] = origin[3];
}

void printMatrix(long long * matrix){
    cout << matrix[0] << "\t" << matrix[1] << endl << matrix[2] << "\t" << matrix[3] << endl;
}

long long * fastExp(long long * matrix, long long pow){
    long long cPow = 0;
    int bitCounter = 1;
    long long * tmp = new long long[4];
    copyMatrix(matrix, tmp);

    long long * exit = new long long[4]{1, 0, 0, 1};
    if((pow & 1) != 0) {
        exit = matrix2x2Mult(exit, tmp);
        cPow = 1;
    }

    while (cPow < pow){
        tmp = matrix2x2Mult(tmp, tmp);
        if((pow & (1 << bitCounter)) != 0) {
            exit = matrix2x2Mult(exit, tmp);
            cPow = cPow | (1 << bitCounter);
        }
        bitCounter++;
    }

    return exit;
}

int main()
{
    int inputSize, cIndex;
    long long  sum;
    long long * inputs, * matrix, * tmpMatrix;
    while(true){
        cin >> inputSize;
        if(inputSize == 0) return 0;
        inputs = new long long[inputSize];

        for(int i = 0; i < inputSize; i++) cin >> inputs[i];
        sum = 0;
        cIndex = inputSize - 1;
        matrix = new long long[4]{1, 1, 1, 0};

        if((inputSize & 1) == 0){
            cIndex--;
            matrix = fastExp(new long long[4]{1, 1, 1, 0}, inputs[cIndex] + 1);
        }

        while(cIndex >= 0){
            //printMatrix(matrix);
            for(int i = 0; i < inputs[cIndex]; i++){
                sum = (sum + matrix[0]) % MODULO;
                matrix = matrix2x2Mult(matrix, new long long[4]{1, 1, 1, 0});
                //cout << "Sum: " << sum << endl;
            }
            cIndex--;
            if(cIndex > 0){
                tmpMatrix = fastExp(new long long[4]{1, 1, 1, 0}, inputs[cIndex]);
                matrix = matrix2x2Mult(matrix, tmpMatrix);
            }
            cIndex--;
        }
        cout << sum << "\n";

    }

    return 0;
}
