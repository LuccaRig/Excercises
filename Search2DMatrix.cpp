#include<iostream>
#include<vector>

using std::vector;



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //Numero de linhas 
        int n = matrix[0].size() - 1; //Numero de colunas

        if(m <= 0){
            return false;
        }

        //Binary Search Algorithm:
        int left = 0;
        int right = m;
        
        do{
            if(!((left+right)%2)){
                for(int j=0;j<(n-1);j++){
                    if(matrix[right][j] == target){
                        return true;
                    }
                }
                right = right - 1;
            }

            int MidValue = (left + right)/2;

            
            if(target == matrix[MidValue][0]){
                return true;
            }
            else if(target < matrix[MidValue][0]){
                right = MidValue - 1;
            }
            else if(target > matrix[MidValue][0]){
                
                for(int j=0;j<n;j++){ //Adicionar um Binary Search tambem
                    if(matrix[MidValue][j] == target){
                        return true;
                    }
                }
                
                left = MidValue + 1; 
            }


        }while(right >= left);

        return false;
    }
};

int main(){
    Solution Solution1;
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix2{{1,1}};
    vector<vector<int>> matrix3{{1,3}};


    if(Solution1.searchMatrix(matrix, 3)){
        std::cout << "True" << std::endl;
        }else{
            std::cout << "False" << std::endl;
        }
    if(Solution1.searchMatrix(matrix2, 2)){
        std::cout << "True" << std::endl;
        }else{
            std::cout << "False" << std::endl;
        }
    if(Solution1.searchMatrix(matrix3, 3)){
        std::cout << "True" << std::endl;
        }else{
            std::cout << "False" << std::endl;
        }

    return 0;
}

