#ifndef LEFT4DEAD_PROTECTEDQUEUE_H
#define LEFT4DEAD_PROTECTEDQUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <deque>
#include <climits>

struct ClosedQueue : public std::runtime_error {
    ClosedQueue() : std::runtime_error("The queue is closed") {}
};

template<typename T, class C = std::deque<T> >
class ProtectedQueue {
private:
    std::queue<T, C> q;
    const unsigned int max_size;

    bool closed;

    std::mutex mtx;
    std::condition_variable is_not_full;
    std::condition_variable is_not_empty;

public:
    ProtectedQueue() : max_size(UINT_MAX - 1), closed(false) {}
    explicit ProtectedQueue(const unsigned int max_size) : max_size(max_size), closed(false) {}


    bool try_push(T const& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw ClosedQueue();
        }

        if (q.size() == this->max_size) {
            return false;
        }

        if (q.empty()) {
            is_not_empty.notify_all();
        }

        q.push(val);
        return true;
    }

    bool try_pop(T& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            return false;
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        val = q.front();
        q.pop();
        return true;
    }

    void push(T const& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw ClosedQueue();
        }

        while (q.size() == this->max_size) {
            is_not_full.wait(lck);
        }

        if (q.empty()) {
            is_not_empty.notify_all();
        }

        q.push(val);
    }


    T pop() {
        std::unique_lock<std::mutex> lck(mtx);

        while (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            is_not_empty.wait(lck);
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        T const val = q.front();
        q.pop();

        return val;
    }

    void close() {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw std::runtime_error("The queue is already closed.");
        }

        closed = true;
        is_not_empty.notify_all();
    }

private:
    ProtectedQueue(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(const ProtectedQueue&) = delete;

};

template<>
class ProtectedQueue<void*> {
private:
    std::queue<void*> q;
    const unsigned int max_size;

    bool closed;

    std::mutex mtx;
    std::condition_variable is_not_full;
    std::condition_variable is_not_empty;

public:
    explicit ProtectedQueue(const unsigned int max_size) : max_size(max_size), closed(false) {}


    bool try_push(void* const & val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw ClosedQueue();
        }

        if (q.size() == this->max_size) {
            return false;
        }

        if (q.empty()) {
            is_not_empty.notify_all();
        }

        q.push(val);
        return true;
    }

    bool try_pop(void*& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            return false;
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        val = q.front();
        q.pop();
        return true;
    }

    void push(void* const& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw ClosedQueue();
        }

        while (q.size() == this->max_size) {
            is_not_full.wait(lck);
        }

        if (q.empty()) {
            is_not_empty.notify_all();
        }

        q.push(val);
    }


    void* pop() {
        std::unique_lock<std::mutex> lck(mtx);

        while (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            is_not_empty.wait(lck);
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        void* const val = q.front();
        q.pop();

        return val;
    }

    void close() {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw std::runtime_error("The queue is already closed.");
        }

        closed = true;
        is_not_empty.notify_all();
    }

private:
    ProtectedQueue(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(const ProtectedQueue&) = delete;

};


template<typename T>
class ProtectedQueue<T*> : private ProtectedQueue<void*> {
public:
    explicit ProtectedQueue(const unsigned int max_size) : ProtectedQueue<void*>(max_size) {}


    bool try_push(T* const& val) {
        return ProtectedQueue<void*>::try_push(val);
    }

    bool try_pop(T*& val) {
        return ProtectedQueue<void*>::try_pop((void*&)val);
    }

    void push(T* const& val) {
        return ProtectedQueue<void*>::push(val);
    }


    T* pop() {
        return (T*) ProtectedQueue<void*>::pop();
    }

    void close() {
        return ProtectedQueue<void*>::close();
    }

private:
    ProtectedQueue(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(const ProtectedQueue&) = delete;

};

#endif // LEFT4DEAD_PROTECTEDQUEUE_H
