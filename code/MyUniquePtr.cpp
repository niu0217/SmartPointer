#include<iostream>

using namespace std;

class Type {
public:
    int a = 1;
};

template<typename T>
class my_unique_ptr {
public:
    my_unique_ptr(T* ptr = nullptr)
        : m_ptr(ptr) { }
    ~my_unique_ptr() {
        delete m_ptr;
    }
    T& operator*() const {
        return *m_ptr;
    }
    T* operator->() const {
        return m_ptr;
    }
    operator bool() const {
        return m_ptr;
    }

    //move construct
    my_unique_ptr(my_unique_ptr&& rhs) noexcept {
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
    }
    //move assignment
    my_unique_ptr& operator=(my_unique_ptr&& rhs) noexcept {
        m_ptr = rhs.m_ptr;
        rhs.m_ptr = nullptr;
        return *this;
    }
private:
    T* m_ptr;
};

int main()
{
    my_unique_ptr<Type> sptr(new Type);
    my_unique_ptr<Type> sptr2(std::move(sptr));

    my_unique_ptr<Type> sptr3;
    sptr3 = std::move(sptr2);
    return 0;
}

