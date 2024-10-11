#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <ctime>

#include "OrderStatus.h"

class Order {
private:
    int orderNumber;
    double orderSum;
    OrderStatus status;
    std::time_t orderDate;

public:
    Order(int number, double sum, OrderStatus status, std::time_t date) :
        orderNumber(number), orderSum(sum), status(status), orderDate(date) {}

    int getOrderNumber() const { return orderNumber; }
    double getOrderSum() const { return orderSum; }
    OrderStatus getStatus() const { return status; }
    std::time_t getOrderDate() const { return orderDate; }

    void setStatus(OrderStatus newStatus) { status = newStatus; }
    
    // ??????? ??? ?????? ?????????? ? ??????
    void print() const {
        std::cout << "Order number: " << orderNumber << " - "
            << "Summ: " << orderSum << " - "
            << "Status: ";
      switch (status) {
      case OrderStatus::new_order:
          std::cout << "New";
          break;
      case OrderStatus::processing:
          std::cout << "processing";
          break;
      case OrderStatus::shipped:
          std::cout << "shipped";
          break;
      }
      
      
      
      
    
          std::cout<< " - Date: " << std::ctime(&orderDate) << std::endl;
    }
};

