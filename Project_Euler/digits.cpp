#include <iostream>
#include <vector>

class Digits
{
private:
  long signficant;
  std::vector<short> digits;
public:
  template <typename Number>
  Digits(Number);
  Digits(std::vector<short>);
  Digits(std::string);
  Digits(const Digits&);
  std::ostream& operator<<(std::ostream &os);
  void print(long);
  Digits operator+(const Digits&);
  bool operator<(const Digits&);
};

template <typename Number>
Digits::Digits(Number number)
{
  long count = 0;
  while(number > 0){
    digits.push_back(number % 10);
    number /= 10;
    count++;
  }
  signficant = count;
}

Digits::Digits(const Digits& copy) : 
    digits(copy.digits), signficant(copy.signficant)
{ }

Digits::Digits(std::vector<short> vec){
  long count = 0;
  for(long i = 0; i < vec.size(); i++){
    count++;
    digits.push_back(vec[i]);
  }
  signficant = count;
}

Digits::Digits(std::string s){
  long count = 0;
  for(long i = s.size()-1; i >= 0; i--){
    digits.push_back((s[i] - '0'));
    count++;
  }
  signficant = count;
}

bool Digits::operator<(const Digits& d){
  if (this->signficant == d.signficant){
    return (this->digits.back() < d.digits.back());
  }
  return (this->signficant < d.signficant);
}

Digits Digits::operator+(const Digits& d){
  Digits new_d(0);
  short add =0;
  long i =0;
  short aux;
  if(*this < d){
    for(; i < this->signficant;i++){
      aux = this->digits[i] + d.digits[i] + add;
      if (aux >= 10){
        add = aux / 10;
        aux %= 10;
      }else
        add = 0;
      new_d.digits.push_back(aux);
    }
    for(; i < d.signficant; i++){
      aux = d.digits[i] + add;
      if (aux >= 10){
        add = aux / 10;
        aux %= 10;
      }else
        add = 0;
      new_d.digits.push_back(aux);
    }
  }else{
    for(; i < d.signficant;i++){
      aux = this->digits[i] + d.digits[i] + add;
      if (aux >= 10){
        add = aux / 10;
        aux %= 10;
      }else
        add = 0;
      new_d.digits.push_back(aux);
    }
    for(; i < this->signficant; i++){
      aux = this->digits[i] + add;
      if (aux >= 10){
        add = aux / 10;
        aux %= 10;
      }else
        add = 0;
      new_d.digits.push_back(aux);    
    }
  }
  if (add > 0)
    new_d.digits.push_back(add);
  
  new_d.signficant = new_d.digits.size(); 
  return new_d;
}

std::ostream& Digits::operator<<(std::ostream &os){
  for(auto i = signficant-1; i >= 0; i--){
    os << digits[i];
    if(i % 3 == 0)
      os << " ";
  }
  return os;
}

void Digits::print(long rest){
  if (rest >= signficant)
    rest = signficant;
  for(auto i = signficant-1; i >= signficant-rest; i--){
    std::cout << digits[i];
  }
}
