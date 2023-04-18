// playdoh_sharedptr.cpp
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

class PlaydohSPtr {
  Playdoh* play{ nullptr };
  int* counter{ nullptr };
public:

  explicit PlaydohSPtr(Playdoh* p = nullptr) : play(p) { 
    counter = new int; *counter = 1; 
  }
  ~PlaydohSPtr() {
    if (*counter == 1)
      delete play;
    else
      (*counter)--;
  }

  // Copy deleted
  PlaydohSPtr(const PlaydohSPtr& src) {
    *this = src;
  }
  PlaydohSPtr& operator=(const PlaydohSPtr& src) {
    if (this != &src) {
      if (counter != nullptr && *counter == 1)
        delete play;
      play = src.play;
      counter = src.counter;
      (*counter)++;
    }
    return *this;
  }

  // Move
  PlaydohSPtr(PlaydohSPtr&& src) noexcept {
    *this = std::move(src);
  }

  PlaydohSPtr& operator=(PlaydohSPtr&& src) noexcept {
    if (this != &src) {
      play = src.play;
      counter = src.counter;
      src.play = nullptr;
      src.counter = 0;
    }
    return *this;
  }

  // Selection
  Playdoh& operator*() { return *play; }
  Playdoh* operator->() { return play; }

  // Comparison
  bool operator==(void* ptr) {
    return static_cast<void*>(play) == ptr;
  }
  bool operator!=(void* ptr) {
    return !(*this == ptr);
  }
};

void asPlaydoh(const char* col) {
  PlaydohSPtr p(new Playdoh(col, 50));
  p->display(cout);
  {
    PlaydohSPtr p2(p);
    p2->display(cout);
  }
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


  PlaydohSPtr p(new Playdoh("Blue", 10));
  PlaydohSPtr p2(new Playdoh("Red", 10));

  {
    PlaydohSPtr p3(p);
    PlaydohSPtr p4(p2);
  }

}
