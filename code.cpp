#include <iostream>
#include <fstream>
#include <sstream>

int main() {
  std::string str;
  std::stringstream ss;
  std::ifstream infile("in.txt");
  if(infile.is_open()){
    bool gotdim = false;
    int arrdim {}, i {}, k {};
    int** arrArr = new int*[2];
    int sizes[2] {};
    while(getline(infile, str)){
      if(str.empty()){continue;}
      ss << str;
      if(gotdim){
        arrArr[k] = new int[arrdim]();
        for(int j{};j<arrdim;j++){
          ss >> arrArr[k][j];
        }
        gotdim = false;
        k++;
        //delete[] arrArr[i++];
      }else{
        ss >> arrdim;
        sizes[i++] = arrdim;
        gotdim = true;
        if(arrdim <=0){
          std::cout<<"Bad dimension!\n";
          return 2;
        }
      }
      ss.clear();
      ss.str("");
      str = "";
    }
    infile.close();
    std::ofstream outfile("out.txt");
    outfile<<sizes[1]<<"\n";
    outfile<<arrArr[1][sizes[1]-1];
    for(int j=0;j<sizes[1]-1;j++){
      outfile<<" "<<arrArr[1][j];
    }
    outfile << "\n";
    outfile<<sizes[0]<<"\n";
    for(int j=1;j<sizes[0];j++){
      outfile<<arrArr[0][j]<<" ";
    }
    outfile<<arrArr[0][0]<<"\n";
    delete[] arrArr[0];
    delete[] arrArr[1];
    delete[] arrArr;
    outfile.close();
  }else{
    std::cout<<"File not available!\n";
    return 1;
  }
  return 0;
}
