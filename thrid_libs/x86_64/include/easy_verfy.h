 //
 // Created by root on 7/19/25.
 //

 #ifndef SEAV3_EASY_VERFY_H
 #define SEAV3_EASY_VERFY_H
 #include <functional>
 #include <iostream>
 #include <obfuscate.h>
 #include <unordered_map>
 #include <any>
std::string ciphergate_host = OBFUSCATE("http://localhost:8080");// 仅 host 可配置
std::string ciphergate_app_id = OBFUSCATE("1");
std::string ciphergate_client_version = OBFUSCATE("1.0.0");
std::string ciphergate_app_key = OBFUSCATE("V5wXrxIYI0zAi9uUQ7RFWKzod9iojDdy");
std::string ciphergate_app_secret = OBFUSCATE("D91fujPP0c41ynOvcbqKzgoS66FcSHRrkWKG6L5hiCXp5hXV3dyaHCOD8hpb9WsA");
std::string ciphergate_aes_key = OBFUSCATE("cg_demo_key_1234");

 std::unordered_map<std::string, std::function<std::any(std::vector<std::any>)>> method_map;
 #endif //SEAV3_EASY_VERFY_H

