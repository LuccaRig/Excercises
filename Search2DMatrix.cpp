#include<iostream>
#include<vector>

using std::vector;



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;

        while(i<matrix.size() && j>=0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};

int main(){
    Solution Solution1;
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix2{{1,1}};
    vector<vector<int>> matrix3{{1,3}};


    if(Solution1.searchMatrix(matrix, 60)){
        std::cout << "True" << std::endl;
        }else{
            std::cout << "False" << std::endl;
        }
    if(Solution1.searchMatrix(matrix2, 1)){
        std::cout << "True" << std::endl;
        }else{
            std::cout << "False" << std::endl;
        }
    if(Solution1.searchMatrix(matrix3, 0)){
        std::cout << "True" << std::endl;
        }else{
            std::cout << "False" << std::endl;
        }

    return 0;
}

