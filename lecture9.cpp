#include <iostream>
#include <vector>
using namespace std;
void display(vector<vector<int>> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].size(); j++)
    {
      cout << vec[i][j] << " ";
    }
    cout << "\n";
  }
  return;
}
void transpose(vector<vector<int>> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = i + 1; j < vec[i].size(); j++)
    {
      int temp = vec[i][j];
      vec[i][j] = vec[j][i];
      vec[j][i] = temp;
    }
  }
}
void rotate90(vector<vector<int>> &arr)
{
  transpose(arr);
  for (int i = 0; i < arr.size(); i++)
  {
    int l = 0, h = arr[i].size() - 1;
    while (l < h)
    {
      int temp = arr[i][l];
      arr[i][l] = arr[i][h];
      arr[i][h] = temp;
      l++;
      h--;
    }
  }
}
void spiralInClockWise(vector<vector<int>> &arr)
{
  int tle = arr.size() * arr[0].size();
  int dir = -1, sr = 0, sc = 0, er = arr.size() - 1, ec = arr[0].size() - 1;
  while (tle != 0){
    dir = (dir + 1) % 4;
    if (dir == 0){
      for (int i = sc; i <= ec; i++){
        cout << arr[sr][i] << " ";
        tle--;
      }
      sr++;
    }
    else if(dir==1){
      for(int i=sr;i<=er;i++){
        cout<<arr[i][ec]<<" ";
        tle--;
      }
      ec--;
    }
    else if(dir==2){
      for(int i=ec;i>=sc;i--){
        cout<<arr[er][i]<<" ";
        tle--;
      }
      er--;
    }
    else{
      for(int i=er;i>=sr;i--){
        cout<<arr[i][sc]<<" ";
        tle--;
      }
      sc++;
    }
  }
}
int main() {
  int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  // for(int i=0;i<4;i++){
  //   for(int j=0;j<3;j++){
  //     cout<<arr[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }

  vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  // transpose(vec);
  // rotate90(vec);
  spiralInClockWise(vec);
  // display(vec);
  return 0;
}