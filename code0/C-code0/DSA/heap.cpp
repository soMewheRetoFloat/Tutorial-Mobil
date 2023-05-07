#include <iostream>

using std::cout;
using std::endl;

template<class T> class heap {
 private:
    T* data = nullptr;
    static T* trash;
    int capacity = 0;
    int Size = 0;
 public:
    heap() = default;
    int size() {
        return Size;
    };
    int capa() {
        return capacity;
    }

    void checksize() {
        if (capacity == 0) {
            capacity = 1;
            data = new T[capacity];
        }
        else if(Size >= capacity) {
            capacity *= 2;
            T* tmp = data;
            data = new T[capacity];
            for (int i = 0; i < Size; ++i) {
                data[i] = tmp[i];
            }
        }
    }

    void swap(T& x, T& y) {
        T tmp = x;
        x = y;
        y = tmp;
    }

    void shiftdown (int cur) {
        int child = 2 * cur + 1;
        while (child < Size) {
            if (child + 1 < Size && data[child + 1] < data[child]) {
                ++child;
            }
            if (data[child] < data[cur]) {
                swap(data[child], data[cur]);
                cur = child;
                child = 2 * cur + 1;
            }
            else break;
        }
    }

    void shiftup (int cur) {
        int rrot = (cur - 1) / 2;
        while (rrot > 0) {
            if (data[rrot] > data[cur]) {
                swap(data[rrot], data[cur]);
                cur = rrot;
                rrot = (cur - 1) / 2;
            }
            else break;
        }
    }

    void initheap(T* initsize, int sizx) {
        data = initsize;
        capacity = size = sizx;
        for (int i = (sizx - 2) / 2; i >= 0; --i) {
            shiftdown(i);
        }
    }

    void push(T val) {
        checksize();
        int cur = size();
        data[Size++] = val;
        shiftup(cur);
    }

    void pop() { //删除堆顶
        swap(data[0], data[Size - 1]);
        Size--;
        shiftdown(0);
    }

    T& top() {
        if (size())
        return data[0];
        else {
            cout << "error" << endl;
            return trash;
        }
    }

    virtual ~heap() {
        if (data) delete[] data;
    }
};

template<class T>
T* heap<T>::trash = new T;

int main() {
    return 0;
}