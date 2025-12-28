#include <iostream>
#include <chrono>
#include <string>
#include <vector>

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
    const int totalItems = 1000000;
    DynamicArray<int> myArr;
    std::vector<int> stdVec;

    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<totalItems; i++) myArr.push_back(i+1);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_time_dyn = end1-start1;

    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<totalItems; i++) stdVec.push_back(i+1);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_time_vec = end2-start2;

    std::cout << "My Dynamic Array took: " << elapsed_time_dyn.count() << std::endl;
    std::cout << "STL vector took: " << elapsed_time_vec.count() << std::endl;
}