// Title:   Assignment I - Task 1 - Problm 2
// Purpose: Matrix Manipulation Program
// Author:  youssef mohamed mohamed ID: 20170349  / yassien ahmed ghoneim ID: 20170333 / youssef hassan elsayed bashandy ID: 20170340
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <valarray>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  valarray<int> data;       //valarray that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
  int data1 [] = {1,0,0,0,1,0,0,0,1};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};
  int data4 [] = {5,7,3,9,5,2,7,1,2};
  int data5 [] = {14,8,34,9,67,0,3,6,12};

  matrix mat1, mat2, mat3, mat4, mat5, mat6;
  createMatrix (3, 3, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  createMatrix (3, 3, data4, mat4);
  createMatrix (3, 3, data5, mat5);
  cin>>mat6;
  cout<<mat1<<endl<<mat2<<endl<<mat3<<endl<<mat4<<endl<<mat5<<endl<<mat6<<endl;
  mat1==mat2;
  cout<<endl;
  mat1!=mat2;
  cout<<endl;
  cout<<isSquare(mat1);
  cout<<endl;
  cout<<isSymetric(mat4);
  cout<<endl;
  cout<<isIdentity(mat3);
  cout<<endl<<endl;
  cout<<transpose(mat5)<<endl;
  cout<<mat1+mat4<<endl;
  cout<<mat1-mat4<<endl;
  cout<<(mat1*mat4)<<endl;
  cout<<mat1+0<<endl;
  cout<<mat1-0<<endl;
  cout<<mat1*0<<endl;
  mat1+=mat4;
  cout<<mat1<<endl;
  mat1-=mat4;
  cout<<mat1<<endl;
  ++mat1;
  cout<<mat1<<endl;
  --mat1;
  cout<<mat1<<endl;
  mat1+=0;
  cout<<mat1<<endl;
  mat1-=0;
  cout<<mat1<<endl;
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data.resize (row * col);
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}
ostream& operator<< (ostream& out, matrix mat){
int x=0;
for (int i=0; i<mat.row*mat.col;i++){
    out<<mat.data[i]<<"    ";
    x++;
    if(x==mat.col){
        out<<endl;
        x=0;
    }
}
return out;
}

bool   operator== (matrix mat1, matrix mat2){
bool x=true;
for (int i=0;i<sizeof(mat1.data);i++){
    if(mat1.data[i]!=mat2.data[i]){
        x=false;
        cout<<"matrices are not identical"<<endl;
        cout<<x;
        break;
}
}
if (x==true){
    cout<<"matrices are identical"<<endl;
}
return x;

}
bool   operator!= (matrix mat1, matrix mat2){
bool x=true;
for (int i=0;i<sizeof(mat1.data);i++){
    if(mat1.data[i]!=mat2.data[i]){
        x=false;
        cout<<"matrices are not identical"<<endl;
        break;
}
}
if (x==true){
    cout<<"matrices are identical"<<endl;
}
return x;

}

bool   isSquare   (matrix mat){
if (mat.row==mat.col){

    cout<<"matrix is square"<<endl;
    return true;
}
else {
    cout<<"not square"<<endl;
    return false;
}

}
bool   isSymetric (matrix mat){
if (mat.row==mat.col){
int ctr=0;
    for(int i=0;i<mat.col;i++){
        if (mat.data[ctr]!=mat.data[i]){
            cout<<"matrix is not symmetric"<<endl;
            return false;
        }
        ctr+=mat.col;
    }
    cout<<"matrix is symmetric"<<endl;
}
else {
    cout<<"matrix is not symmetric"<<endl;
}
}
bool   isIdentity (matrix mat){

if(mat.row!=mat.col)
    {
    cout<<"matrix is not identity ";
    return false;
}
else
{
bool check=true;
int x=mat.row+1;
for (int i=0;i<mat.row*mat.col;i=i+x)
   {
    if (mat.data[i]!=1)
        {
            check=false;
            cout<<"matrix is not identity ";
            break;
    }
}
if (check==true)
    {
        for(int i=0;i<mat.row*mat.col;++i)
            {
                if (i%x==0){
                    continue;
                }
                else {
                    if (mat.data[i]!=0){
                            cout<<"matrix is not identity ";
                        return false;
                    }
                }
        }
}
cout<<"matrix is identity ";
return true;
}
}
matrix transpose(matrix mat){
matrix ans;
ans.row=mat.col;
ans.col=mat.row;
ans.data.resize(mat.row*mat.col);
int z=0;
for (int j=0;j<mat.col;++j){
        for (int i=0;i<mat.row;++i){
        ans.data[z]=mat.data[j + i * mat.col];
        z++;
        }
}
return ans;
}
/*-----------------------------------------------------------*/
matrix operator+= (matrix& mat4, matrix mat5){
    if(mat4.row==mat5.row&&mat4.col==mat5.col){

    for(int i = 0; i<mat4.row*mat4.col ; i++){
        mat4.data[i]=mat4.data[i]+mat5.data[i];
    }
    }
    else{
        cout<<"sum is not possible because of different dimensions"<<endl;
    }
};
matrix operator-= (matrix& mat4, matrix mat5){
if(mat4.row==mat5.row&&mat4.col==mat5.col){
        for(int i = 0; i<mat4.row*mat4.col ; i++){
        mat4.data[i]=mat4.data[i]-mat5.data[i];
    }
}
else{
    cout<<"difference not possible because matrices have different dimensions"<<endl;
}
};
matrix operator+= (matrix& mat, int scalar){
cout<<"please enter a number to add to the elements of the matrix :";
cin >> scalar;
for( int i = 0 ; i < mat.row*mat.col ; i++){
    mat.data[i]=mat.data[i]+scalar;
}
return mat;
};
matrix operator-= (matrix& mat, int scalar){
cout<<"please enter a number to subtract from the elements of the matrix :";
cin >> scalar;
for( int i = 0 ; i < mat.row*mat.col ; i++){
    mat.data[i]=mat.data[i]-scalar;
}
return mat;
};
void   operator++ (matrix& mat){
for(int i = 0; i<mat.row*mat.col ; i++){
        mat.data[i]=mat.data[i]+1;
    }
};
void   operator-- (matrix& mat){
for(int i = 0; i<mat.row*mat.col ; i++){
        mat.data[i]=mat.data[i]-1;
    }
};
istream& operator>> (istream& in, matrix& mat){
    cout<<"enter number of rows and columns :"<<endl;
    int r,c;
    in>>r>>c;
    mat.row=r;
    mat.col=c;
    mat.data.resize(r*c);
    cout<<"input the elements the matrix :"<<endl;
    for(int i=0;i<r*c;++i)
    {
        in>>mat.data[i];
    }
    return in;

};


/*-----------------------------------------------------------------------------------------------------------------------------*/
matrix operator+  (matrix mat1, matrix mat2){
    if (mat1.row == mat2.row && mat1.col == mat2.col){
        matrix result;
        result.row = mat1.row;
        result.col = mat1.col;
        result.data.resize(mat1.row * mat1.col);
        for (int i=0; i<mat1.row*mat1.col; i++){
            result.data[i] = mat1.data[i]+mat2.data[i];
        }
        return result;
    }
    else{
        cout<<"Can't be added"<<endl;
    }

}

matrix operator-  (matrix mat1, matrix mat2){
        if (mat1.row == mat2.row && mat1.col == mat2.col){
        matrix diff;
        diff.row = mat1.row;
        diff.col = mat1.col;
        diff.data.resize(mat1.row * mat1.col);
        for (int i=0; i<mat1.row * mat1.col; i++){
            diff.data[i] = mat1.data[i] - mat2.data[i];
        }
        return diff;
    }
    else{
        cout<<"Can't be subtracted"<<endl;
    }
}

matrix operator*  (matrix mat1, matrix mat2){
    matrix ans;
    ans.row=mat1.row;
    ans.col=mat2.col;
    ans.data.resize(mat1.row*mat2.col);
for(int i=0;i<mat1.row;++i)
{
    for(int j=0;j<mat2.col;++j)
    {
        int sum=0;
        for(int k=0;k<mat2.row;++k)
        {
            sum=sum+mat1.data[i*mat1.col+k]*mat2.data[k*mat2.col+j];
        }
        ans.data[i*mat2.col+j]=sum;
    }
}
return ans;
}

matrix operator+  (matrix mat1, int scalar){
    matrix res2;
    res2.row = mat1.row;
    res2.col = mat1.col;
    res2.data.resize(mat1.row*mat1.col);
    cout << "Enter the number you want to add : " << endl;
    cin >> scalar;
    for (int i=0; i<mat1.row * mat1.col; i++){
        res2.data[i] = mat1.data[i] + scalar;
    }
    return res2;
}

matrix operator-  (matrix mat1, int scalar){
    matrix diff2;
    diff2.row = mat1.row;
    diff2.col = mat1.col;
    diff2.data.resize(mat1.row*mat1.col);
    cout << "Enter the number you want to subtract : " << endl;
    cin >> scalar;
    for (int i=0; i<mat1.row * mat1.col; i++){
        diff2.data[i] = mat1.data[i] - scalar;
    }
    return diff2;

}
matrix operator*  (matrix mat1, int scalar){
    matrix prod2;
    prod2.row = mat1.row;
    prod2.col = mat1.col;
    prod2.data.resize(mat1.row*mat1.col);
    cout << "Enter the number you want to multiply : " << endl;
    cin >> scalar;
    for (int i=0; i<mat1.row * mat1.col; i++){
        prod2.data[i] = mat1.data[i] * scalar;
    }
    return prod2;
}

