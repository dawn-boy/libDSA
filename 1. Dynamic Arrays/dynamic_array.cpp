#include <iostream>
#include <string>

struct Location{
    int x;
    int y;
    std::string name;
    int id;
};

template <typename T>
class DynamicArray{
private:
    T* data;
    int index;
    int size;

public:
    DynamicArray(){
        size = 2;
        index = 0;
        data = new T[size];
    }
    ~DynamicArray(){
        delete[] data;
    }
    void push_back(const T loc){
        if(index == size) resize();

        data[index] = loc;
        index++;
    }
    void show() const {
        for(int i = 0; i < size; i++) std::cout << data[i].name << " ";
        std::cout << std::endl;
    }
    void resize(){
        std::cout << "Extending from " << size << " to " << size*2 << std::endl;
        size *= 2;
        T* newData = new T[size];

        for(int i = 0; i < index; i++) newData[i] = data[i];

        delete[] data;
        data = newData;
    }
};


int main(){

    Location myHome;
    myHome.x = 20;
    myHome.y = 30;
    myHome.id = 1;
    myHome.name = "Home";

    Location dest;
    dest.x = 50;
    dest.y = 50;
    dest.id = 2;
    dest.name = "Destination";

    DynamicArray<Location> map;

    map.push_back(myHome);
    map.show();
    map.push_back(dest);
    map.show();
    map.push_back(myHome);
    map.show();
    map.push_back(myHome);
    map.show();
    map.push_back(myHome);
    map.show();
    map.push_back(dest);
    map.show();
    map.push_back(dest);
    map.show();
    map.push_back(dest);
    map.show();

    return 0;
}
