#include <iostream>
#include <fstream>
#include <string>
#include <list>

class Hash{
  private:
    static const int hashgroup = 10;
    std::list<std::pair<int, std::string>>table[hashgroup];

    public:
      bool isEmpty() const;
      int function(int key);
      void insertItem(int key, std::string t);
      void removeItem(int key);
      std::string searchItem(int key);
      void getTable();
      

};

bool Hash::isEmpty() const{
    int sum{};//brace initialization (sum = 0)
    for(int i{}; i<hashgroup; i++){
        sum+=table[i].size();
    }

    if (!sum){
        return true;
    }
    return false;
}

int Hash::function(int key){
    return key % hashgroup;
}

void Hash::insertItem(int key, std::string t){
    int hashVal = function(key);
    auto& cell = table[hashVal];
    auto bItr = begin(cell);//iteration from the begining
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr->second = t;
            std::cout<< "key exists. value replaced."<< std::endl;
            break;

        }
    }
    if(!keyExists){
        cell.emplace_back(key, t);
    }

    return;

}

void Hash::removeItem(int key){
    int hashVal = function(key);
    auto& cell = table[hashVal];
    auto bItr = begin(cell);//iteration from the begining
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr = cell.erase(bItr);
            std::cout<< "item removed"<< std::endl;
            break;

        }
    }

    if(!keyExists){
        std::cout<<"key not found" <<std::endl;
    }

    return;
}