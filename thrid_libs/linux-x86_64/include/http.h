#pragma once
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>


namespace shttp {

    struct http_response {
        bool success;     // true if the request was successful, false otherwise
        long code;         // the HTTP status code
        std::string data; // the response data
        std::string error;// the error message
        std::string  content_type; // the content type
    };
    // example usage: http_xxx("你的域名,可带https://头也可不带","请求参数","自定义请求头,自行了解规范",true/*就使用https了需要服务器支持*/,true/*是否打印错误日志*/);
    http_response http_get(const std::string &url, const std::string &header = "Content-Type: application/x-www-form-urlencoded", bool log = false);// send a GET request to the specified URL and return the response

    http_response http_post(const std::string &url, const std::string &params = "", const std::string &header = "Content-Type: application/x-www-form-urlencoded", bool log = false);// send a GET request to the specified URL and return the response

    struct ws_response {
        bool success = false;
        std::string data;
        std::string error;
        std::uint64_t sent = 0;
        int flags = 0;
        std::size_t bytes_left = 0;
    };

    struct ws_client;
    using ws_client_ptr = std::shared_ptr<ws_client>;

    // Connect to ws:// or wss:// endpoint.
    ws_client_ptr ws_connect(const std::string &url, bool log = false);

    // Send text/binary frame over websocket.
    ws_response ws_send(const ws_client_ptr &client, const std::string &data, bool binary = false, bool log = false);

    // Receive one websocket frame chunk.
    ws_response ws_recv(const ws_client_ptr &client, std::size_t max_size = 4096, bool log = false);

    // Explicit close. Shared pointer release will also cleanup.
    void ws_close(ws_client_ptr &client);

}// namespace shttp
