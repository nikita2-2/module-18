#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <ctime>
#include "Orderr.h"

int main() {
    // Создание вектора заказов
    std::vector<Order> orders;

    // Заполнение вектора заказов
    orders.push_back(Order(1, 1000.0, OrderStatus::new_order, std::time(nullptr) - 10));
    orders.push_back(Order(2, 5500.0, OrderStatus::new_order, std::time(nullptr) - 6));
    orders.push_back(Order(3, 200.0, OrderStatus::processing, std::time(nullptr) - 1));
    orders.push_back(Order(4, 1500.0, OrderStatus::shipped, std::time(nullptr) - 30));
    orders.push_back(Order(5, 6000.0, OrderStatus::new_order, std::time(nullptr) - 7));

    std::cout << "first order list: \n" << std::endl;
    for (const auto& order : orders) {
        order.print();
    }

    // Обновление статуса заказов, если прошло больше 5 секунд
    std::transform(orders.begin(), orders.end(), orders.begin(), [](Order& order) {
        if (order.getStatus() == OrderStatus::new_order && (std::time(nullptr) - order.getOrderDate()) > 5) 
        {
            order.setStatus(OrderStatus::processing);
        }
        return order;
        }
    );
    // Вывод обновленного списка заказов
    std::cout << "Update orders list:\n" << std::endl;
    for (const auto& order : orders) {
        order.print();
    }



    // Поиск заказа с суммой больше 5000 в статусе "processing"
    auto it = std::find_if(orders.begin(), orders.end(), [](const Order& order) {
        return order.getOrderSum() > 5000 && order.getStatus() == OrderStatus::processing;
        });

    if (it != orders.end()) {
        std::cout << "Find order number " << it->getOrderNumber()
            << " and summ " << it->getOrderSum() << std::endl;
    }
    else {
        std::cout << "Order not found." << std::endl;
    }
    system("pause");
    return 0;
}
