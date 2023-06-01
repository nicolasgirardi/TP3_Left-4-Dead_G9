cmake_minimum_required(VERSION 3.10)
project(Left4Dead)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCE_FILES common/include/Protocol.h common/src/Protocol.cpp common/include/Socket.h common/src/Socket.cpp common/include/ResolverError.h common/src/ResolverError.cpp common/include/LibError.h common/src/LibError.cpp common/include/Resolver.h common/src/Resolver.cpp client/src/SenderServer.cpp common/include/Thread.h common/include/ProtectedQueue.h client/include/UserAction.h client/src/UserAction.cpp client/src/main.cpp client/include/ProtocoloActions.h client/include/ReceiverUpdate.h client/src/ReceiverUpdate.cpp client/include/ReceiverUpdate.h client/include/GameUpdate.h client/include/StateTypes.h client/src/GameUpdate.cpp client/src/Client.cpp)

add_executable(Left4Dead ${SOURCE_FILES})

target_link_libraries(Left4Dead Qt5::Widgets)
