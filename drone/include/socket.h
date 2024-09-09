#ifndef SOCKET_H
#define SOCKET_H

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length);
bool setupSocket();

#endif