// smart_ptr.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
using namespace std;

class Playdoh {
  char* colour;
  int weight;
public:
  Playdoh(const char* col, int wei) : weight(wei) {
    colour = nullptr;
    if (col != nullptr) {
      colour = new char[strlen(col) + 1];
      strcpy(colour, col);
    }
  }

  ~Playdoh() { delete[] colour; }

  void display(ostream& os) const {
    if (colour[0] == '\0')
      throw "Empty String Colour";
    os << "Playdoh colour: " << colour << " weight: " << weight << endl;
  }
};

ostream& operator<<(ostream& os, const Playdoh& p) {
  p.display(os);
  return os;
}

void asPlaydoh(const char* col) {
  std::unique_ptr<Playdoh> p (new Playdoh(col, 50));
  p->display(cout);
}


void asSharedPlaydoh(const char* col) {
  std::shared_ptr<Playdoh> p (new Playdoh(col, 50));
  p->display(cout);
  {
    std::shared_ptr<Playdoh> p2(p);
    p2->display(cout);
  }
}

#define uni

int main() {

#ifdef uni
  try {
    asPlaydoh("Red");
    asPlaydoh("Blue");
    asPlaydoh("Green");
    asPlaydoh("");
  }
  catch (const char* e) {
    cout << "Caught: " << e << endl;
  }
#else
  try {
    asSharedPlaydoh("Red");
    asSharedPlaydoh("Blue");
    asSharedPlaydoh("Green");
    asSharedPlaydoh("");
  }
  catch (const char* e) {
    cout << "Caught: " << e << endl;
  }
#endif
}