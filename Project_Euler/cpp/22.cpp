
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

std::map<char, int> create_score(){
  std::vector<char> chars {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U', 'V', 'W','X','Y','Z'};
  std::map <char, int> map;
  int i = 1;
  for(auto j: chars){
    map.insert(std::pair<char, int>(j, i));
    i++;
  }
  return map;
}

int main(){
  std::ifstream file("p022_names.txt");
  std::string all;
  file >> all;
  std::vector<std::string> names;
  std::string word = "";
  for(auto ch : all){
    if(ch != '"' && ch != ','){
      word.push_back(ch);
    }else if(ch == ','){
      names.push_back(word);
      word = "";
    }
  }
  names.push_back(word);
  std::sort(names.begin(), names.end());
  auto scores = create_score();
  long long int solution = 0;
  for(int i = 0; i < names.size(); i++){
    word = names.at(i);
    int score = 0;
    for(auto ch: word){
      score += scores.find(ch)->second;
    }
    solution += score * (i+1);
  }
  std::cout << solution<< "\n";
  file.close();
  return 0;
}
