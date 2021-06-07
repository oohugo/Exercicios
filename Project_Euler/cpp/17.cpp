#include <iostream>
#include <string>
#include <assert.h>
#include <map>


int number_name_length(int number){

  std::map<int, std::string> names  = {{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},
    {6,"six"},{7,"seven"},{8,"eight"},{9,"nine"},{10,"ten"},{11,"eleven"},{12,"twelve"},
    {13,"thirteen"},{14,"fourteen"},{15,"fifteen"},{16,"sixteen"},{17,"seventeen"},{18,"eighteen"},
    {19,"nineteen"},{20,"twenty"},{30,"thirty"},{40,"forty"},{50,"fifty"},{60,"sixty"},
    {70,"seventy"},{80,"eighty"},{90,"ninety"},{100,"hundred"},{1000,"thousand"}};
  
  if(number < 20)
    return names[number].length();

  if(number < 100)
    if(number % 10 ==0 )
      return names[(number / 10)*10].length();
    else
      return names[(number / 10)*10].length() + names[number % 10].length();
  
  if(number < 1000){
    if(number % 100 == 0)
      return names[100].length() + names[number /100].length();
    return names[100].length() + names[number /100].length() + 3 + number_name_length(number%100);
  }
  return names[1000].length() + names[1].length();
}

long number_length_to(int number){
  long sum = 0;
  for(int i = 1; i <= number; i++){
    sum += number_name_length(i);
  }
  return sum;
}


int main(){
  
  assert(number_name_length(5) == 4);
  assert(number_length_to(99) == 854);
  assert(number_name_length(342) == 23);
  assert(number_name_length(115) == 20);
  std::cout << number_length_to(1000) << "\n";
  return 0;

  
}