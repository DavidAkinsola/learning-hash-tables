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
      void searchItem(int key);
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

void Hash:: searchItem(int key){
    int hashVal = function(key);
    auto& cell = table[hashVal];
    auto bItr = begin(cell);//iteration from the begining
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            std::cout<< "\n\nsearch results...";
            std::cout<< "key: " <<bItr->first<<" value: "<<bItr->second<<std::endl;
            break;

        }
    }

    if(!keyExists){
        std::cout<<"key not found" <<std::endl;
    }

    return;
}

void Hash::getTable(){
    for(int i{}; i<hashgroup; i++){
        if(table[i].size()==0) continue;

        auto bItr = table[i].begin();
        for(; bItr!=table[i].end(); bItr++){
            std::cout<< "key: " <<bItr->first<<"value: "<<bItr->second<<std::endl;
        }
    }
    return;
}

int main(){
    Hash h;

    if(h.isEmpty()){
        std::cout<<"success";
    }else{
        std::cout<<"failed"<<std::endl;
    }

    h.insertItem(155, "a");
    h.insertItem(156, "b");
    h.insertItem(153, "c");
    h.insertItem(167, "d");
    h.insertItem(138, "e");
    h.insertItem(148, "f");
    h.insertItem(169, "g");
    h.insertItem(177, "h");
    h.insertItem(120, "i");
    h.insertItem(131, "j");
    h.insertItem(191, "k");

    h.getTable();

    h.searchItem(169);

    

    if(h.isEmpty()){
        std::cout<<"failed"<<std::endl;
    }else{
        std::cout<<"success"<<std::endl;
    }


    return 0;


}