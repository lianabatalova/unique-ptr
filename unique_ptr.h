#pragma once

class UniquePtr {
public:
    UniquePtr() {
        ptr_ = nullptr;
    }

    UniquePtr(const UniquePtr& up) = delete;
    UniquePtr& operator=(const UniquePtr& up) = delete;

    UniquePtr(UniquePtr&& up) {
        ptr_ = up.ptr_;
        up.ptr_ = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& up) {
        Reset();
        ptr_ = up.ptr_;
        up.ptr_ = nullptr;
        return *this;
    }

    explicit UniquePtr(TestClass* ptr) {
        ptr_ = ptr;
    }

    void Reset() {
        delete ptr_;
        ptr_ = nullptr;
    }

    void Reset(TestClass* ptr) {
        Reset();
        ptr_ = ptr;
    }

    TestClass* Get() {
        return ptr_;
    }

    TestClass* operator->() {
        return ptr_;
    }

    TestClass& operator*() {
        return *ptr_;
    }

    ~UniquePtr() {
        delete ptr_;
    }

private:
    TestClass* ptr_;
};