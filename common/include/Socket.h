#ifndef LEFT4DEAD_SOCKET_H
#define LEFT4DEAD_SOCKET_H
class Socket {
private:
    int skt;
    bool closed;
    explicit Socket(int skt);

public:
    Socket(const char *hostname, const char *servname);

    explicit Socket(const char *servname);

    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    Socket(Socket&&);

    Socket();

    Socket& operator=(Socket&&);

    int sendsome(const void *data, unsigned int sz, bool *was_closed);
    int recvsome(void *data, unsigned int sz, bool *was_closed);

    int sendall(const void *data, unsigned int sz, bool *was_closed);
    int recvall(void *data, unsigned int sz, bool *was_closed);

    Socket accept();

    void shutdown(int how);

    int close();

    ~Socket();
};
#endif //LEFT4DEAD_SOCKET_H
