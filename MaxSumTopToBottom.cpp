#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class PyramidTriangle{
    private:
        int** matrix=NULL;          //Our dynamic matrix
        void readData(string);      //For reading data from the file
        void maxSum();              //Fuction which calculates the max sum
        int size;                   //Size of the one edge

    public:
        PyramidTriangle(string);    //Constructor definition
        ~PyramidTriangle();         //Destructor definition

};

//Constructor
PyramidTriangle::PyramidTriangle(string filename){
    readData(filename);
    maxSum();
}

//Destructor to free memory
PyramidTriangle::~PyramidTriangle(){
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void PyramidTriangle::maxSum(){
  
    for (int i = size-2;i>=0; i--)
    {
        for (int j = 0; j<=i; j++)
        {   
            //cout<<"i : "<<i<<" j : "<<j<<endl;
            if(matrix[i][j]>0){
                //cout<<"in if 1"<<endl;
                //cout<<matrix[i][j]<<endl;
                if(matrix[i+1][j]>0){
                    
                    //cout<<"in if 2"<<endl;
                    //cout<<matrix[i][j]<<endl;
                    if(matrix[i+1][j+1]>0){
                        //cout<<"in if 3"<<endl;
                        //cout<<matrix[i][j]<<endl;
                        matrix[i][j]+=max(matrix[i+1][j],matrix[i+1][j+1]);
                    }else{
                        //cout<<"in else 3"<<endl;
                        matrix[i][j]+=matrix[i+1][j];
                        //cout<<matrix[i][j]<<endl;
                    }
                }else{
                    //cout<<"in else 2"<<endl;
                    //cout<<matrix[i+1][j+1]<<endl;
                    
                    if(matrix[i+1][j+1]>0){
                        //cout<<"in if 4"<<endl; 
                        matrix[i][j]=matrix[i][j]+matrix[i+1][j+1];
                        //cout<<matrix[i][j]<<endl;
                    }
                }
            }

        }
        
    }
    cout<<"Max sum : "<<matrix[0][0];
}

void PyramidTriangle::readData(string filename){
   
   /**
    * This lambda function returns true if the number
    * passed to it is not prime number.Otherwise, it returns
    * false. Works with O(sqrt(n))  
   */
   auto notPrime =[](int number){
        if(number==1){
            return true;
        }
        int temp_check_number=2;
        while((temp_check_number*temp_check_number)<=number){
            if(number%temp_check_number==0){
                return true;
            }
            temp_check_number++;
        }
        return false;
    };


    /**
     * Used dynamic memory allocation and stl file functions
     * in order to read data from the file.
    */
    ifstream fin;
    fin.open(filename.c_str(),std::ios::in); 
    string temp_line_stream;
    
    //Here we find one edge of the triangle
    int triangle_size=0;
    while(getline(fin,temp_line_stream)){
        //stream line := iss
        istringstream iss(temp_line_stream);
        triangle_size++;
    }
    size=triangle_size;
    fin.close();
    //Here we find one edge of the triangle

    //This is to create out matrix dynamically
    matrix=new int*[triangle_size];
    for (int i = 0; i < triangle_size; i++)
    {
        matrix[i]=new int[triangle_size];
    }
    //This is to create out matrix dynamically


    //This lines for filling the matrix
    fin.open(filename.c_str(),std::ios::in); 
    int row=0;
    int temp;
    while(getline(fin,temp_line_stream)){
        //stream line
        //cout<<temp_line_stream<<endl;
        istringstream iss(temp_line_stream);
        for (int i = 0; i<=row; i++)
        {   
            iss>>temp;
            if(notPrime(temp))
            {
                matrix[row][i]=temp;
            }else
            {
                //If the number is prime number then we make
                //related matrix value -1 because while we are
                //making calculation we cant use prime numbers
                //This -1 value will be a flag for us in main 
                //calculation function maxSum()
                matrix[row][i]=-1;
            } 
        }
        row++;
    }
    fin.close();
    //This lines for filling the matrix

}

int main(){ 

    string filename;
    cin>>filename;
    PyramidTriangle Test(filename);

    return 0;
}
