// playdoh_uniqueptr.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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

class PlaydohUPtr {
  Playdoh* play{ nullptr };

public:

  explicit PlaydohUPtr(Playdoh* p = nullptr) : play(p) {}
  ~PlaydohUPtr() { delete play; }
  
  // Copy deleted
  PlaydohUPtr(const PlaydohUPtr& src) = delete;
  PlaydohUPtr& operator=(const PlaydohUPtr& src) = delete;

  // Move
  PlaydohUPtr(PlaydohUPtr&& src) noexcept {
    *this = std::move(src);
  }

  PlaydohUPtr& operator=(PlaydohUPtr&& src) noexcept {
    if (this != &src) {
      delete play;
      play = src.play;
      src.play = nullptr;
    }
    return *this;
  }

  // Selection
  Playdoh& operator*() { return *play; }
  Playdoh* operator->() { return play; }
};

void asPlaydoh(const char* col) {
  PlaydohUPtr p(new Playdoh(col, 50));
  p->display(cout);
}

int main() {

  try {
    asPlaydoh("Red");
    asPlaydoh("Blue");
    asPlaydoh("Green");
    asPlaydoh("");
  }
  catch (const char* e) {
    cout << "Caught: " << e << endl;
  }
}
