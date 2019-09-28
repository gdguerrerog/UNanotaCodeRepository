#include <iostream>

using namespace std;


/*

matrix indexes are:
0 1
2 3

*/
void matrix2x2Mult(long long * m1, long long * m2, long long * exit){
    exit[0] = m1[0]*m2[0] + m1[1]*m2[2];
    exit[1] = m1[0]*m2[1] + m1[1]*m2[3];
    exit[2] = m1[2]*m2[0] + m1[3]*m2[2];
    exit[3] = m1[2]*m2[1] + m1[3]*m2[3];
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

void fastExp(long long * matrix  , long long pow, long long * exit){
    long long cPow = 1;
    int bitCounter = 1;
    long long * tmp = new long long[4];
    long long * tmp2 = new long long[4];
    copyMatrix(matrix, tmp);

    exit[0] = exit[3] = 1;
    exit[1] = exit[2] = 0;
    if((pow & 1) != 0){
        matrix2x2Mult(exit, tmp, tmp2);
        copyMatrix(tmp2, exit);
    }

    while (cPow < pow){
        matrix2x2Mult(tmp, tmp, tmp2);
        copyMatrix(tmp2, tmp);
        if(((pow >> bitCounter) & 1) != 0){
            matrix2x2Mult(exit, tmp, tmp2);
            copyMatrix(tmp2, exit);
        }
        if(cPow == 0) cPow = 1;
        else cPow = cPow << 1;
        bitCounter++;

        /*cout << "--------------------------\n";
        printMatrix(tmp);
        cout << endl;
        printMatrix(exit);
        cout << endl;
        cout << "pow: " << cPow << ", bit: " << bitCounter << endl;*/

    }
}

int main()
{
    int inputSize, cIndex;
    long long currentPow;
    long long * inputs, matrix;
    while(true){
        cin >> inputSize;
        if(inputSize == 0) return 0;
        inputs = new long long[inputSize];

        for(int i = 0; i < inputSize; i++) cin >> inputs[i];
        currentPow = cIndex = 0;
        matrix = new long long[4]{1, 1, 1, 0};
        if((inputSize & 1) == 0)


    }
    return 0;
}
